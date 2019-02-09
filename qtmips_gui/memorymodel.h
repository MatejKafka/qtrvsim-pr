// SPDX-License-Identifier: GPL-2.0+
/*******************************************************************************
 * QtMips - MIPS 32-bit Architecture Subset Simulator
 *
 * Implemented to support following courses:
 *
 *   B35APO - Computer Architectures
 *   https://cw.fel.cvut.cz/wiki/courses/b35apo
 *
 *   B4M35PAP - Advanced Computer Architectures
 *   https://cw.fel.cvut.cz/wiki/courses/b4m35pap/start
 *
 * Copyright (c) 2017-2019 Karel Koci<cynerd@email.cz>
 * Copyright (c) 2019      Pavel Pisa <pisa@cmp.felk.cvut.cz>
 *
 * Faculty of Electrical Engineering (http://www.fel.cvut.cz)
 * Czech Technical University        (http://www.cvut.cz/)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 ******************************************************************************/

#ifndef MEMORYMODEL_H
#define MEMORYMODEL_H

#include <QAbstractTableModel>

class MemoryModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum MemoryCellSize {
        CELLSIZE_BYTE,
        CELLSIZE_HWORD,
        CELLSIZE_WORD,
    };

    MemoryModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    void updateHeaderLabels();
    inline unsigned int cellSizeBytes() {
        switch (cell_size) {
        case CELLSIZE_BYTE:
            return 1;
        case CELLSIZE_HWORD:
            return 2;
        case CELLSIZE_WORD:
            return 4;
        }
        return 0;
    }

    enum MemoryCellSize cell_size;
    unsigned int cells_per_row;
    std::uint32_t index0_offset;
};


#endif // MEMORYMODEL_H
