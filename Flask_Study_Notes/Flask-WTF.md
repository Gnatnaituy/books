Flask-WTF

### **Field**

**TextField**  >>  <iuput type='text'>

**BooleanField**  >> <input type='checkbox'>

**TextAreaField**  >> <textarea>  \DeciamlField\IntegerField

**RadioField**  >> <input type='radio'>  

```python
 Gender = RadioField('Gender', choices = [('M','Male'), ('F','Female')])
```

**SelectField**  >>  select form element

```python
language = SelectField('Languages', choices = [('cpp', 'C++'), ('py', 'Python')])
```

**PasswordField**  >> <input type='password'>

**SubmitField**  >>  <input type='submit'>

#### **Validators**

**Datarequired**("Please enter your name")

**Email**()

**IPAddress**()

**Length**(1, 64)

**NumberRange**(1, 64)

**URL**()

