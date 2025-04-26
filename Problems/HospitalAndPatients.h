#ifndef LEETCODE_HOSPITALANDPATIENTS_H
#define LEETCODE_HOSPITALANDPATIENTS_H

#include <queue>
#include <map>

/*
 * There is a Hospital which contain N rooms from 1 to N -1.
 * There is a Queue of Patients outside the Hospital.
 * Each patient will be served in a single room and each patient has a time duration that
 * it will take for the treatment.
 * The rooms are allocated to patients by the lowest index (if the room is free).
 * Initially room1 will be given to the patient, then if the 2nd patient comes and
 * the 1st room is still busy, then the room2 will be given to the 2nd patient.
 * now suppose the 1st patient treatment is completed, and the room1 is free now,
 * and a new patient comes, then room1 will be given to the new patient.
 * Each Patient has a start time also (Consider this as appointment time for him,
 * it needs not to be a time format, use Integer for this).
 * The patients standing in the queue are in non decreasing order of their start time.
 * means if the first patient start time = 1, then the second patient start time will be >= 1.
 * Now the rooms will be allocated to each patients one by one. we have to calculate that by
 * the end when all the patients are treatment done, Which is the room in which the maximum
 * no of patients have been entered?
 */

class HospitalAndPatients {

public:
    int maxAllottedRoom(int N, std::queue<std::pair<int, int>> &patients) {     //patients: start, duration
        std::vector<int> roomEndTimes(N, 0);
        std::vector<int> roomFreq(N, 0);

        while (!patients.empty()) {
            auto patient = patients.front();
            int patientStartTime = patient.first;
            int patientDuration = patient.second;
            patients.pop();

            int assignedRoom = -1;

            for (int i = 1; i <= N; ++i) {
                if (roomEndTimes[i] <= patientStartTime) {
                    assignedRoom = i;
                    break;
                }
            }

            if (assignedRoom != -1) {
                int newEndTime = patientStartTime + patientDuration;
                roomEndTimes[assignedRoom] = newEndTime;
                roomFreq[assignedRoom]++;
            }
        }

        int highestFreq = 0;
        int roomOfHighestFreq = 1;
        for (int i = 1; i <= N; ++i) {
            if (roomFreq[i] > highestFreq) {
                highestFreq = roomFreq[i];
                roomOfHighestFreq = i;
            }
        }

        return roomOfHighestFreq;
    }
};


#endif //LEETCODE_HOSPITALANDPATIENTS_H
