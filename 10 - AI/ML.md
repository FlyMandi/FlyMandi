# What is Machine Learning?

Machine Learning can be reduced to a function that takes a set of data as input, has a predetermined 'right' and 'wrong' answer and in building the model uses an error minimisation function. Then, that model is used to either classify, say if an image includes a dog or a cat, or approximate a result, say to predict traffic intensity in a given junction in the future.

Here's what this function could look like in principle:

```math
\begin{bmatrix} w_1 & w_2 & w_3 & w_4 \\\ w_1 & w_2 & w_3 & w_4 \\\ w_1 & w_2 & w_3 & w_4 \end{bmatrix} \begin{bmatrix} x_1 \\\ x_2 \\\ x_3 \\\ x_4 \end{bmatrix} + \begin{bmatrix} b \\\ b \\\ b \end{bmatrix} = \begin{bmatrix} w_1x_1 + w_2x_2 + w_3x_3 + w_4x_4 + b \\\ w_1x_1 + w_2x_2 + w_3x_3 + w_4x_4 + b \\\ w_1x_1 + w_2x_2 + w_3x_3 + w_4x_4 + b \end{bmatrix} &rarr; \begin{bmatrix} a_1 \\\ a_2 \\\ a_3 \end{bmatrix}
```
Where our input set is [ $x_1$, $x_2$, $x_3$, $x_4$ ], our weights are $w_1$ through $w_4$ and [ $a_1$, $a_2$, $a_3$ ] our neurons. What all this means or how exactly it all works is currently not as important as understanding that the working principle of a Machine Learning model can be boiled down to a mathematical function and written out in its entirety. There is no black magic and it won't take over the world.

# Machine Learning vs Generative AI; ChatGPT in principle

A generative AI is a program that is built around an ML model, the same way a car is built around an engine. It's the heart and soul and the most vital component, but by no means the only part of the car that makes it work. Just like the power of the engine needs to go to the wheels somehow, the ML model is interfaced with via a pre-processing layer. Just like a car needs steering, the initial user prompt for a Gen. AI is handled by a logic layer and context management system.

A typical Chatbot might handle your input (prompt) like this:

1. Turn user prompt into a processable dataset (i.e. ascii array)
2. Use previous messages (and responses) to approximate context
3. Generate ML model response based on user prompt (the actual 'magic' happens here!)
4. Add formatting and flair (like Microsoft Copilot's follow-up questions and quirky emojis)
5. Process ML model output, check for offensive responses and similarly undesirable words/phrases, refine

The fact of the matter is, all it's doing is generating, letter by letter (or even pixel by pixel), the most statistically likely response. And of course, if you have any experience, especially with lesser models and services like NovelAI for example, you'll know the model loves to hallucinate. Worse still, since the entire prompt/response history, depending on the service, is fed back again into the model, every time the bot hallucinates it puts the hallucinations back into the dataset with all of the other potentially valuable data.

# Problems with Machine Learning

- Generalisation (false positives, false negatives and the impossibility of perfect generalisation)
    Because all we're doing is making the most accurate guess based on our model's training data, the reliability of a Machine Learning model could never reach a full 100%. A hard-coded, exact calculation will always be best where accuracy is valued over output. However, once you understand that all the ML model does is give the best approximation, it can be a very powerful tool. Generalisation is the ability of the ML model to predict future data that is not part of the original data set, in other words, the whole reason we'd use an ML model to begin with. Because if it didn't, then the original data set could just be used in a hard-coded function that returns the desired result. An ML model won't, by definition, give false positives or false negatives on the training data itself, but Generalisation is where these _will_ occur and the bigger and more tailored the dataset, the more the error minimisation can do its work and false positives/negatives are lessened. A false generalisation could lead to what's known as a hallucination in a chatbot, for example, or putting 6 fingers on a hand when generating an image.

    Given a set of finite data, the ability to create an ML model that responds perfectly accurate when using generalisation, that is, data points that weren't part of the original data set, is impossible. At least, to guarantee that it does, is. It is possible that by chance an ML model generates a perfect response every time, but highly unlikely and in a practical reality, impossible. Actually, even if it did, the fact that it's unverifiable, even with perfect responses, means we have to treat it with the right amount of scepticism. 
- Overfitting, Underfitting and Noise in training data
    Given a set of positives and negatives, (our initial 'right' and 'wrong' answers) as a set of training data, for example 'dog' and 'no dog' in respect to a picture, some of those positives and negatives might be false, because of noise, human error or other factors. This rings especially true when using large sets of data - the probability of a non-perfect training data element rises. In such cases, it is important to note that it might be an incorrect approach to train the ML model in such a way that it works 100% reliably across every element of the training data, because of something known as overfitting. To understand overfitting, you have to imagine an area in a graph where all of our positives accumulate. Around it, there are negatives scattered. We would then use this area for every future point in the graph, and if it falls within the area, we classify it as a positive. Well, safe to say we should draw our area of positives around _all_ of the positives of the training data set, no? This would avoid all false negatives on the training data set. Now, imagine that there is one outliar, a single false positive in the training data leading to the area (because we chose a rectangle) to be much larger than without it. If that is a false positive in the training data, or one with noise, this now means that we are going to be generalizing false positives in that entire area in the future. Another approach would be to change the shape of the area, making it more complex and thus adding (in this case unnecessary) computational complexity and the need for significantly more training data, because we're dealing with more complex shapes. Underfitting is the same basic principle, but in reverse. Instead of choosing a rectangle, one might draw a simple line, which would lead to a significant loss in true positives.
    So, the act of overfitting can lead to slightly more accurate results with the set of training data, at the significant cost of less accurate generalization and way higher complexity. 
    The response then is to sacrifice the accuracy of the ML model with the outliars that were fed to it as data input, because we don't use the ML model to accurately categorize the training data - we did that ourselves for the purporse of creating a model that can generalize. The act of overcorrecting overfitting can lead to underfitting, however. This is the basic dilemma and it's more of a case-by-case scenario where often a holistic human understanding and intuition is required in order to construct a better ML model.
# Anatomy of Machine Learning

//TODO

## What are weights?

## What's a bias?

## Whatis a neuron?