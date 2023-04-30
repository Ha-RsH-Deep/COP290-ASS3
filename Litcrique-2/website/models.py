from .import db 
from flask_login import UserMixin
from sqlalchemy.sql import func
import sqlite3
import pandas as pd
import csv
from datetime import datetime


class User(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    email = db.Column(db.String(150), unique=True)
    password = db.Column(db.String(150))
    first_name = db.Column(db.String(150))
    last_name = db.Column(db.String(150))
    user_name = db.Column(db.String(150), unique=True)
    reviews = db.relationship('Review', backref='user', lazy=True)
    reading_list = db.relationship('Book', secondary='user_book', backref=db.backref('users', lazy=True))


class UserBook(db.Model):
    __tablename__ = 'user_book'
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), primary_key=True)
    book_id = db.Column(db.String, db.ForeignKey('book.id'), primary_key=True)
    date_added = db.Column(db.DateTime, default=datetime.utcnow)

class Book(db.Model):
    id = db.Column(db.String(500), primary_key=True)
    title = db.Column(db.String(250), unique=True)
    description = db.Column(db.String(100000))
    authors = db.Column(db.String(200))
    image = db.Column(db.String(250))
    previewLink = db.Column(db.String(250))
    publisher = db.Column(db.String(250))
    infoLink = db.Column(db.String(250))
    Categories = db.Column(db.String(500))
    rating = db.Column(db.Integer)

class Review(db.Model):
    id = db.Column(db.String(500), primary_key=True)
    user_name =db.Column(db.String , db.ForeignKey('user.user_name'))
    rating_user = db.Column(db.Integer)
    book_title = db.Column(db. Integer, db.ForeignKey('book.title'))
    review_summary = db.Column(db.String(10000))
    review_text = db.Column(db.String(100000))

