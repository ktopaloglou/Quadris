#include <memory>
#include "jblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

JBlock::JBlock(int level, int col, int row, int height = 2) :
	AbstractBlock{ level, col, row, height } {}

char JBlock::getShape() const {
	return 'J';
}

Coordinates JBlock::get1stCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 2, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row - 2 };
		return cell;
	} else {
		Coordinates cell{ col, row };
		return cell;
	}
}

Coordinates JBlock::get2ndCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else {
		Coordinates cell{ col + 1, row };
		return cell;
	}
}

Coordinates JBlock::get3rdCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row - 2 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row };
		return cell;
	} else {
		Coordinates cell{ col + 2, row };
		return cell;
	}
}

Coordinates JBlock::get4thCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col, row };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 2, row };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col + 1, row - 2 };
		return cell;
	} else {
		Coordinates cell{ col, row - 1 };
		return cell;
	}
}
Coordinates JBlock::get1stCell() {
	return get1stCell(orientation);
}

Coordinates JBlock::get2ndCell() {
	return get2ndCell(orientation);
}

Coordinates JBlock::get3rdCell() {
	return get3rdCell(orientation);
}

Coordinates JBlock::get4thCell() {
	return get4thCell(orientation);
}