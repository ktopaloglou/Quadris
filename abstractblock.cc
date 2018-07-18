#include <memory>
#include "abstractblock.h"
#include "cell.h"
#include "abstractlevel.h"

using namespace std;

AbstractBlock::AbstractBlock(int level, int col, int row):
	level{ level }, col{ col }, row{ row } {
	orientation = 1;
} 

int AbstractBlock::getOrientation() const {
	return orientation;
}
void AbstractBlock::setOrientation(int newOrientation) {
	orientation = newOrientation;
}
int AbstractBlock::getLevel() {
	return level;
}
int AbstractBlock::getRow() const {
	return row;
}
int AbstractBlock::getCol() const {
	return col;
}
void AbstractBlock::setRow(int newRow) {
	row = newRow;
}
void AbstractBlock::setCol(int newCol) {
	col = newCol;
}
bool AbstractBlock::isHeavy() const {
	return (level >= 3);
}
Coordinates AbstractBlock::getReference() const {
	Coordinates cell{ col, row };
	return cell;
}