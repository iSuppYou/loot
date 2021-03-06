/*  LOOT

A load order optimisation tool for Oblivion, Skyrim, Fallout 3 and
Fallout: New Vegas.

Copyright (C) 2014-2016    WrinklyNinja

This file is part of LOOT.

LOOT is free software: you can redistribute
it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

LOOT is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with LOOT.  If not, see
<https://www.gnu.org/licenses/>.
*/

#ifndef LOOT_GUI_QUERY_GET_INSTALLED_GAMES_QUERY
#define LOOT_GUI_QUERY_GET_INSTALLED_GAMES_QUERY

#include "gui/state/loot_state.h"
#include "gui/query/json.h"
#include "gui/query/query.h"

namespace loot {
class GetInstalledGamesQuery : public Query {
public:
  GetInstalledGamesQuery(LootState& state) : state_(state) {}

  std::string executeLogic() {
    BOOST_LOG_TRIVIAL(info) << "Getting LOOT's detected games.";
    return getInstalledGamesAsJson();
  }

private:
  std::string getInstalledGamesAsJson() const {
    YAML::Node temp = YAML::Node(state_.getInstalledGames());
    if (temp.size() > 0)
      return JSON::stringify(temp);
    else
      return "[]";
  }

  LootState& state_;
};
}

#endif
