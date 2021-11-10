#pragma once

#include <string>
#include <vector>

class ZipFile;

class Epub
{
private:
  // the title read from the EPUB meta data
  std::string m_title;
  // the cover image
  std::string m_cover_image_item;
  // where is the EPUBfile?
  std::string m_path;
  // the spine of the EPUB file
  std::vector<std::string> m_spine;
  // the base path for items in the EPUB file
  std::string m_base_path;

  // find the path for the content.opf file
  bool find_content_opf_file(ZipFile &zip, std::string &content_opf_file);

public:
  Epub(const std::string &path);
  ~Epub() {}
  std::string &get_base_path() { return m_base_path; }
  bool load();
  bool loadIndex();
  const std::string &get_path() const { return m_path; }
  const std::string &get_title();
  const std::string &get_cover_image_item();
  uint8_t *get_item_contents(const std::string &item_href, size_t *size = nullptr);
  std::string &get_spine_item(int spine_index);
  int get_spine_items_count();
};