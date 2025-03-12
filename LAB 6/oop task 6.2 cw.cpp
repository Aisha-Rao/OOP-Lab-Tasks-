#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MediaFile {
protected:
    string filePath;
    size_t size;  

public:
    MediaFile(const string& path, size_t fileSize)
        : filePath(path), size(fileSize) {}

    virtual void play() {
        cout << "Playing " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping " << filePath << endl;
    }

    virtual void showDetails() const {
        cout << "File Path: " << filePath << ", Size: " << size << " bytes" << endl;
    }

    virtual ~MediaFile() {}  
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolutionWidth;
    int resolutionHeight;

public:
    VisualMedia(const string& path, size_t fileSize, int width, int height)
        : MediaFile(path, fileSize), resolutionWidth(width), resolutionHeight(height) {}

    void showDetails() const override {
        MediaFile::showDetails();
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }

    virtual ~VisualMedia() {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(const string& path, size_t fileSize, int rate)
        : MediaFile(path, fileSize), sampleRate(rate) {}

    void showDetails() const override {
        MediaFile::showDetails();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }

    virtual ~AudioMedia() {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(const string& path, size_t fileSize, int width, int height, int rate)
        : MediaFile(path, fileSize), VisualMedia(path, fileSize, width, height), AudioMedia(path, fileSize, rate) {}

    void play() override {
        cout << "Playing video with audio and visual content: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping video: " << filePath << endl;
    }

    void showDetails() const override {
        MediaFile::showDetails();
        cout << "Video Details: ";
        VisualMedia::showDetails();
        AudioMedia::showDetails();
    }

    virtual ~VideoFile() {}
};

class ImageFile : public VisualMedia {
public:
    ImageFile(const string& path, size_t fileSize, int width, int height)
        : VisualMedia(path, fileSize, width, height) {}

    void play() override {
        cout << "Displaying image: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping image display: " << filePath << endl;
    }

    virtual ~ImageFile() {}
};

class AudioFile : public AudioMedia {
public:
    AudioFile(const string& path, size_t fileSize, int rate)
        : AudioMedia(path, fileSize, rate) {}

    void play() override {
        cout << "Playing audio: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping audio: " << filePath << endl;
    }

    virtual ~AudioFile() {}
};

int main() {
    MediaFile* mediaFiles[] = {
        new VideoFile("video1.mp4", 1024, 1920, 1080, 44100),
        new ImageFile("image1.jpg", 512, 1280, 720),
        new AudioFile("audio1.mp3", 256, 44100)
    };

    for (auto media : mediaFiles) {
        media->play();
        media->showDetails();
        media->stop();
        cout << endl;
    }

    for (auto media : mediaFiles) {
        delete media;
    }

    return 0;
}

