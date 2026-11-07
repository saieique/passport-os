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
    // Ten fixed presets: five CNR channels plus four Shenzhen stations and one
    // Guangdong news channel. The count must stay within the station table (10
    // slots). CNR only publishes TS/AAC HLS (ngcdn002), every other carrier
    // dropped its MP3 relays, so those five ride the HLS path; the rest are
    // plain MP3. Descriptions reuse strings the pixel font already ships.
    {"中国之声", "推荐电台 · 新闻综合", "http://ngcdn002.cnr.cn/live/zgzs/index.m3u8", 0},
    {"经济之声", "推荐电台 · 财经资讯", "http://ngcdn002.cnr.cn/live/jjzs/index.m3u8", 0},
    {"音乐之声", "推荐电台 · 经典老歌", "http://ngcdn002.cnr.cn/live/yyzs/index.m3u8", 0},
    {"文艺之声", "推荐电台 · 轻松旋律", "http://ngcdn002.cnr.cn/live/wyzs/index.m3u8", 0},
    {"大湾区之声", "推荐电台 · 城市资讯", "http://ngcdn002.cnr.cn/live/hxzs/index.m3u8", 0},
    {"深圳新闻广播", "推荐电台 · 新闻综合", "http://lhttp.qingting.fm/live/1270/64k.mp3", 0},
    {"深圳飞扬971", "推荐电台 · 经典老歌", "http://lhttp.qingting.fm/live/1271/64k.mp3", 0},
    {"深圳交通广播", "推荐电台 · 城市资讯", "http://lhttp.qingting.fm/live/1272/64k.mp3", 0},
    {"深圳生活广播", "推荐电台 · 轻松旋律", "http://lhttp.qingting.fm/live/1273/64k.mp3", 0},
    {"广东新闻广播", "推荐电台 · 新闻综合", "http://lhttp.qingting.fm/live/1254/64k.mp3", 0},
#endif
};
