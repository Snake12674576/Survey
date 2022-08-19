#include <iostream>
#include <string>
#include <vector>

struct Quest {
  std::string question;
  std::string correctAnswer;
  int score;
};

std::vector<Quest> data;
int globalScore;

Quest CreateQuest(const char *question, const char *correctAnswer, int score) {
  Quest result;

  result.question = question;
  result.correctAnswer = correctAnswer;
  result.score = score;

  return result;
}

void LoadData() {
  data.push_back(CreateQuest("Сколько всего было царей в России", "17", 7));
  data.push_back(CreateQuest("Сколько костей у взрослого человека", "200", 5));
  data.push_back(CreateQuest("Столица Словакии", "Братислава", 5));
}

void ProcessQuest(const Quest quest) {
  std::cout << quest.question << '?' << std::endl << "Ответ: ";

  std::string answer;
  std::cin >> answer;
  if (answer == quest.correctAnswer) {
    std::cout << "Правильно!" << std::endl;
    globalScore += quest.score;
  } else {
    std::cout << "Неправильно!" << std::endl;
  }

  std::cout << std::endl;
}

int main(int argc, char **argv) {
  LoadData();

  int maxScore;

  for (auto &&q : data) {
    ProcessQuest(q);
    maxScore += q.score;
  }

  std::cout << "Ты набрал " << globalScore << " баллов" << std::endl
            << "Максимальное колличество баллов: " << maxScore << std::endl;

  return 0;
}
