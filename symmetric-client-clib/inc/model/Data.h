/**
 * Licensed to JumpMind Inc under one or more contributor
 * license agreements.  See the NOTICE file distributed
 * with this work for additional information regarding
 * copyright ownership.  JumpMind Inc licenses this file
 * to you under the GNU General Public License, version 3.0 (GPLv3)
 * (the "License"); you may not use this file except in compliance
 * with the License.
 *
 * You should have received a copy of the GNU General Public License,
 * version 3.0 (GPLv3) along with this library; if not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef SYM_DATA_H
#define SYM_DATA_H

#include "io/data/CsvData.h"
#include "model/TriggerHistory.h"
#include "util/Date.h"

#define SYM_DATA_EVENT_INSERT "I"
#define SYM_DATA_EVENT_UPDATE "U"
#define SYM_DATA_EVENT_DELETE "D"
#define SYM_DATA_EVENT_RELOAD "R"
#define SYM_DATA_EVENT_SQL "S"
#define SYM_DATA_EVENT_CREATE "C"
#define SYM_DATA_EVENT_BSH "B"

typedef struct SymData {
    long dataId;
    char *rowData;
    char *oldData;
    char *pkData;
    char *channelId;
    char *transactionId;
    char *tableName;
    char *eventType;
    char *sourceNodeId;
    char *externalData;
    char *nodeList;
    SymDate *createTime;
    char *routerId;
    int triggerHistId;
    SymTriggerHistory *triggerHistory;
    void (*destroy)(struct SymData *this);
} SymData;

SymData * SymData_new(SymData *this);

void SymData_destroy(SymData *this);

#endif