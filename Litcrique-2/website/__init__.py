from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from os import path
from flask_login import LoginManager
import sqlite3
import pandas as pd
import csv
import uuid


db = SQLAlchemy()
DB_NAME = "LITCRITQUE.db"

def create_app():
    app = Flask(__name__)
    app.config['SECRET_KEY'] = "uuhffvdsjkfbjdsxkjc"
    app.config['SQLALCHEMY_DATABASE_URI'] = f'sqlite:///{DB_NAME}'
    db.init_app(app)
    
    from .views import views
    from .auth import auth 

    app.register_blueprint(views, url_prefix ='/')
    app.register_blueprint(auth , url_prefix ='/')


    from .models import User, UserBook ,Review,Book

    with app.app_context():
        db.create_all()




    # df = pd.read_csv('/home/harshdeep/Desktop/LitCritique/website/books_data.csv')

    # # data clean up
    # df.columns = df.columns.str.strip()

    # # add review_id column
    # df['id'] = [str(uuid.uuid4()) for _ in range(len(df))]


    # # load data into SQL 
    # with app.app_context():
    #     # use the SQLAlchemy engine to create a connection to the database
    #     engine = db.engine.connect()

    #     # write the data to the 'book' table using the SQLAlchemy engine
    #     df.to_sql('book', con=engine, if_exists='replace')

    #     # close the database connection
    #     engine.close()




    # df = pd.read_csv('/home/harshdeep/Desktop/LitCritique/website/Books_rating.csv')

    # # data clean up
    # df.columns = df.columns.str.strip()

    # # add review_id column
    # df['id'] = [str(uuid.uuid4()) for _ in range(len(df))]

    # # load data into SQL 
    # with app.app_context():
    #     # use the SQLAlchemy engine to create a connection to the database
    #     engine = db.engine.connect()

    #     # write the data to the 'book' table using the SQLAlchemy engine
    #     df.to_sql('review', con=engine, if_exists='replace')

    #     # close the database connection
    #     engine.close()


    login_manager = LoginManager()
    login_manager.login_view = 'auth.login'
    login_manager.init_app(app)

    @login_manager.user_loader
    def load_user(id):
        return User.query.get(int(id))

    return app

def create_database(app):
    if not path.exists('website/' + DB_NAME):
        db.create_all(app=app)
        print('Created Database!')