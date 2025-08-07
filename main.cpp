#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>
#include <random>
#include <string>
#include <vector>

std::string wallpaper_path = "/home/teejar/.config/hypr/backgrounds/wallpapers_1";
std::string conf_path = "/home/teejar/.config/hypr/hyprpaper.conf";
std::string selected_path;
std::vector<std::string> wallpaper_names;

int main() {
  system("killall hyprpaper");
  if (!std::filesystem::is_directory(wallpaper_path)) {
    std::cerr << "Invalid wallpaper path";
    return 1;
  }

  for (const auto& file : std::filesystem::recursive_directory_iterator(wallpaper_path)) {
    if (!file.is_directory()) {
      wallpaper_names.push_back(file.path());
    }
  }

  std::random_device rd;
  std::mt19937_64 rng(rd());
  std::uniform_int_distribution<> dist(0, wallpaper_names.size());
  selected_path = wallpaper_names.at(dist(rng));

  std::ofstream out("/" + conf_path, std::ios::out | std::ios::trunc);
  if (out.is_open()) {
    out << "preload = " + selected_path << "\n";
    out << "wallpaper = , " + selected_path << "\n";
    out.close();
  } else {
    std::cerr << "Error opening config file\n";
    return 1;
  }

  system("hyprpaper &");
  std::println("successfully finished");

  return 0;
}
