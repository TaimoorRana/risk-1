#ifndef CONTINENT_H
#define CONTINENT_H

#include <set>
#include "country.h"
#include<QJsonDocument>
#include<QJsonObject>

  QJsonObject Continent::serialize()
  {
      QJsonObject json;
      json["name"]=this->name;
      json["bonus"]=this->troop_bonus;
      json["id"]=this->id;

      QJsonArray array;
      int N= sizeof(this->countries);
     /* for(int i=0; i<N; i++){
          array.append(this->countries[i]);
      }
      json["tab"]=array;*/
  }

  void Continent::deserialize(QJsonObject json){
      this->name=json["name"].toString().toStdString();
      this->id=json["id"].toInt();
      this->troop_bonus=json["bonus"].toInt();
      /*for(int i=0; i<json["tab"].size(); i++){
          this->countries[i]=json["tab"]::at(i).toInt();
      }*/

  }
