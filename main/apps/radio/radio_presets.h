#pragma once
#include "radio_player.h"

// Shared presets: one catalog failure must not leave the radio with one station.
inline constexpr RadioStation kRadioPresets[] = {
#ifdef PASSPORT_RADIO_HLS_TEST
    {"经济之声", "HLS测试 · TS/AAC", "http://ngcdn002.cnr.cn/live/jjzs/index.m3u8", 0},
    {"华语金曲", "HLS测试 · AAC分片", "http://ls.qingting.fm/live/3412131.m3u8?bitrate=64", 0},
    {"凤凰资讯", "HLS测试 · TS/AAC", "http://playtv-live.ifeng.com/live/06OLEEWQKN4_audio.m3u8", 0},
    {"SomaFM", "美国 · MP3测试", "https://ice6.somafm.com/groovesalad-128-mp3", 0},
    {"MANGORADIO", "德国 · MP3测试", "https://mangoradio.stream.laut.fm/mangoradio", 0},
    {"中国之声", "MP3回归测试", "http://lhttp.qingting.fm/live/15318317/64k.mp3", 0},
#else
    // 深圳本地电台 · 蜻蜓 FM 转播（MP3）。这四个流与 radio-browser 目录里
    // 「深圳」查询返回的 URL 一致，duplicate_url() 会自动避免重复占槽位。
    // 统一用 http 明文，省掉 ESP32-C3 上昂贵的 TLS 握手。
    // frequency_decihz 填真实 FM 频率，让表盘指针落在正确刻度上。
    {"深圳先锋898", "推荐电台 · 深圳 · 新闻广播", "http://lhttp.qingting.fm/live/1270/64k.mp3", 898},
    {"深圳飞扬971", "推荐电台 · 深圳 · 音乐广播", "http://lhttp.qingting.fm/live/1271/64k.mp3", 971},
    {"深圳快乐1062", "推荐电台 · 深圳 · 交通广播", "http://lhttp.qingting.fm/live/1272/64k.mp3", 1062},
    {"深圳生活942", "推荐电台 · 深圳 · 生活广播", "http://lhttp.qingting.fm/live/1273/64k.mp3", 942},
    // 中央广播电视总台 · 央广网官方直播（HLS/m3u8 → TS/AAC）。
    // radio_source.cc 会自动识别 .m3u8 和 0x47 TS 同步头，无需额外解码器。
    // 这些 ngcdn002.cnr.cn 直链不带 key，2026-11-07 实测 HTTP 200 且分片可解码。
    {"中国之声", "推荐电台 · 央广 · 新闻综合", "http://ngcdn002.cnr.cn/live/zgzs/index.m3u8", 0},
    {"经济之声", "推荐电台 · 央广 · 财经资讯", "http://ngcdn002.cnr.cn/live/jjzs/index.m3u8", 0},
    {"音乐之声", "推荐电台 · 央广 · 流行音乐", "http://ngcdn002.cnr.cn/live/yyzs/index.m3u8", 0},
    {"文艺之声", "推荐电台 · 央广 · 文化曲艺", "http://ngcdn002.cnr.cn/live/wyzs/index.m3u8", 0},
    {"都市之声", "推荐电台 · 央广 · 都市生活", "http://ngcdn002.cnr.cn/live/dszs/index.m3u8", 0},
    {"乡村之声", "推荐电台 · 央广 · 对农广播", "http://ngcdn002.cnr.cn/live/xczs/index.m3u8", 0},
    // 备用深圳台（同样实测 HTTP 200 / audio/mpeg，替换上面任意一条即可）：
    // 龙岗星光991 FM99.1 → http://lhttp.qingting.fm/live/20160/64k.mp3
    // 交通广播备用源 FM106.2 → http://lhttp.qingting.fm/live/1286/64k.mp3
    // 备用央广频道：神州之声 szzs / 民族之声 mzzs / 香港之声 xgzs / 老年之声 lnzs
    // 路径格式：http://ngcdn002.cnr.cn/live/<短码>/index.m3u8
    // 原「推荐电台」预设（蜻蜓 FM MP3 转播），需要时取消注释：
    // {"怀旧音乐", "推荐电台 · 经典老歌", "http://lhttp.qingting.fm/live/4804/64k.mp3", 0},
    // {"清晨音乐", "推荐电台 · 轻松旋律", "http://lhttp.qingting.fm/live/4915/64k.mp3", 0},
    // {"两广之声", "推荐电台 · 粤语音乐", "http://lhttp.qingting.fm/live/20500149/64k.mp3", 0},
    // {"羊城交通", "推荐电台 · 城市资讯", "http://lhttp.qingting.fm/live/1262/64k.mp3", 0},
    // {"第一财经", "推荐电台 · 财经资讯", "http://lhttp.qingting.fm/live/276/64k.mp3", 0},
    // {"中国之声(MP3)", "推荐电台 · 新闻综合", "http://lhttp.qingting.fm/live/15318317/64k.mp3", 0},
#endif
};
