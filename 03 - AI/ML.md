# What is Machine Learning?

In principle, Machine Learning can be reduced to a function that takes a set of data as input, has a predetermined 'right' and 'wrong' answer and in building the model uses an error minimisation function. Then, that model is used to either classify, say if an image includes a dog or a cat, or approximate a result, say to predict traffic intensity in a given junction in the future.

Here's what this function looks like in principle:
```
//TODO
```

# Problems with Machine Learning

Because all we're doing is making the most accurate guess based on our model's training data, the reliability of a Machine Learning model could never reach a full 100%. A hard-coded, exact calculation will always be best where accuracy is valued over output. However, once you understand that all the ML model does is give the best approximation, it can be a very powerful tool.

# Machine Learning vs Generative AI

//TODO

# ChatGPT and Generative AI in principle

The more I learn about how a model like GPT-4 operates, the more I am astounded at what it can achieve with its stunningly simple principle. Given a set of data (text), which is considered an array/vector of ascii characters, it simply generates an approximate response token (character) by token. Now, there is some more complexity around extra bias selection and logic handling for something like a chatbot, where it doesn't just take all of the user input without question. 

A typical Chatbot might handle your input (prompt) like this:

1. Turn user prompt into a processable dataset (i.e. ascii array)
2. Use previous messages (and responses) to approximate context
3. Generate ML model response based on user prompt (the actual 'magic' happens here!)
4. Add formatting and flair (like Microsoft Copilot's follow-up questions and quirky emojis)
5. Process ML model output, check for offensive responses and similarly undesirable words/phrases, refine

The fact of the matter is, all it's doing is generating, letter by letter (or even pixel by pixel), the most statistically likely response. And of course, if you have any experience, especially with lesser models and services like NovelAI for example, you'll know the model loves to hallucinate. Worse still, since the entire prompt/response history, depending on the service, is fed back again into the model, every time the bot hallucinates it puts the hallucinations back into the dataset with all of the other potentially valuable data.

## What is hallucination?