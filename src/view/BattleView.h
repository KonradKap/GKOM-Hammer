 /*
  * BattleView.h
  *
  * 4.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include "View.h"
#include "commons/Axis.h"

class BattleModel;

class BattleView : public View {
    public:
        explicit BattleView(
            const BattleModel& source, 
            std::unique_ptr<WindowListener> listener = nullptr);
    private:
        void onDraw(const BasicEventArgs&);

        void drawGrid();
        template <Axis AXIS>
            void drawGridIn();

        void drawUnits();

        const BattleModel& source;
};
