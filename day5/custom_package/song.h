#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
struct cmp1 {
  bool operator()(Song const& a, Song const& b) {
    if (a.artist == b.artist) {
      if (a.title == b.title) return a.count > b.count;
      return a.title > b.title;
    } return a.artist > b.artist;
  }
};

struct cmp2 {
  bool operator()(Song const& a, Song const& b) {
    if (a.count == b.count) {
      if (a.artist == b.artist) return a.title > b.title;
      return a.artist > b.artist;
    } return a.count < b.count;
  }
};


CP::priority_queue<Song, cmp1> pq1;
CP::priority_queue<Song,cmp2> pq2;

#endif
