#include <memory>
#include "oblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

OBlock::OBlock(int level, int col, int row,
std::shared_ptr<ScoreKeeper> score) :
	AbstractBlock{ level, col, row, score } {}

char OBlock::getShape() const {
	if (hint) {
    return '?';
	} else {
		return 'O';
	}
}

shared_ptr<AbstractBlock> OBlock::createHint() {
	shared_ptr<AbstractBlock> block = make_shared<OBlock>(getLevel(), 
										getCol(), getRow(), nullptr);
	block->toggleHint();
	return block;
}

Coordinates OBlock::get1stCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else {
		Coordinates cell{ col, row }; // reference cell is first 'O' cell
		return cell;
	}
}

Coordinates OBlock::get2ndCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row };
		return cell;
	} else {
		Coordinates cell{ col + 1, row };
		return cell;
	}
}

Coordinates OBlock::get3rdCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

	if (newOrientation == 3) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col, row };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	}
}

Coordinates OBlock::get4thCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4
	
	if (newOrientation == 3) {
		Coordinates cell{ col, row };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else {
		Coordinates cell{ col, row - 1 };
		return cell;
	}
}
Coordinates OBlock::get1stCell() {
	return get1stCell(getOrientation());
}

Coordinates OBlock::get2ndCell() {
	return get2ndCell(getOrientation());
}

Coordinates OBlock::get3rdCell() {
	return get3rdCell(getOrientation());
}

Coordinates OBlock::get4thCell() {
	return get4thCell(getOrientation());
}
