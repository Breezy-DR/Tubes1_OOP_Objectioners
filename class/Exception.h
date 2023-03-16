#ifndef __PLAYEXCEPTION_H__
#define __PLAYEXCEPTION_H__

#include <exception>
#pragma once
using namespace std;


struct KartuDisabledException : public exception  {
	const char* what() const throw() {
		return "LOL kena disabled";
	}
};

struct KartuUsedException : public exception  {
	const char* what() const throw() {
		return "Tingkatkan literasi! udah dipake kartunya";
	}
};

struct InvalidCommandException : public exception  {
	const char* what() const throw() {
		return "Perintah invalid! Silahkan coba lagi!";
	}
};

struct InvalidChoiceException : public exception  {
	const char* what() const throw() {
		return "Pilihan invalid! Silahkan coba lagi!";
	}
};

struct InvalidFileException : public exception  {
	const char* what() const throw() {
		return "File tidak ditemukan atau tidak dapat dibuka! Silahkan coba lagi!";
	}
};

struct InvalidCardException : public exception  {
	const char* what() const throw() {
		return "Terdeteksi penulisan kartu invalid pada file! Silahkan coba lagi!";
	}
};

struct TooManyCardsException : public exception  {
	const char* what() const throw() {
		return "Jumlah kartu lebih dari 52 kartu! Silahkan coba lagi!";
	}
};

struct TooFewCardsException : public exception  {
	const char* what() const throw() {
		return "Jumlah kartu kurang dari 52 kartu! Silahkan coba lagi!";
	}
};

struct DuplicateCardsException : public exception  {
	const char* what() const throw() {
		return "Terdeteksi duplikat kartu pada file! Silahkan coba lagi";
	}
};

//struct VectorKosongException:public exception{
//    const char* what() const throw() {
//        return "Vector kosong";
//    }
//};
#endif