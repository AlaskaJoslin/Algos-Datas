//Author: Matt Joslin
//Written for Performance of Computer Systems and Networks
//Jan 2016, Problem Set 1 Due Feb 2
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define K 16807
#define M 2147483647
#define NUM_RESULTS 10000
#define NUM_BINS 10
#define LAMBDA 2

//Computes according to the rule
//s(n+1)=(k*s(n))mod(m)
//rn=sn/m
double multiplicative_congruential_method(double seed)
{
  double generated_rand;
  generated_rand = fmod(K * seed, M);
  return generated_rand;
}

double exponential_distribution_method(double r)
{
  return -(log(r) / LAMBDA);
}

//Problem 3) Test the random method below for 10,000 numbers.
//Compute the mean, variance, and the number of numbers in the ranges
//[(j-1)/10 to j/10] for j=1...10
//Use s0=1...2147483646
//    k=16807
//    m=2147483647
//    seed = 1111
void problem_3()
{
  double results[NUM_RESULTS];
  int bins[NUM_BINS] = {0};
  double mean, variance = 0;
  double seed = 1111;
  for(int i = 0; i < NUM_RESULTS; i++)
  {
    seed = multiplicative_congruential_method(seed);
    results[i] = seed / M;
    bins[(int)(results[i] * NUM_BINS)]++;
    mean = mean * i/(i+1) + (results[i]/(i+1));
  }
  for(int i = 0; i < NUM_RESULTS; i++)
  {
    variance = variance * i/(i+1) + pow(fabs(results[i] - mean), 2)/(i+1);
  }
  variance = variance * (NUM_RESULTS) / (NUM_RESULTS - 1);

  printf("Mean: %f\n", mean);
  printf("Variance: %f\n", variance);
  printf("Standard Deviation: %f\n", sqrt(variance));
  for(int i = 0; i < NUM_BINS; i++)
  {
    printf("Bin %i: %i\n", (i+1), bins[i]);
  }
}

//Problem 4) Using the random sequence generated for problem 3, generate
//an exponential distribution. Display the mean and variance. Use lambda = 2.
void problem_4()
{
  double results[NUM_RESULTS];
  int bins[NUM_BINS] = {0};
  double mean, variance = 0;
  double seed = 1111;
  for(int i = 0; i < NUM_RESULTS; i++)
  {
    seed = multiplicative_congruential_method(seed);
    results[i] = exponential_distribution_method(seed / M);
    bins[(int)(results[i] * NUM_BINS)]++;
    mean = mean * i/(i+1) + (results[i]/(i+1));
  }
  for(int i = 0; i < NUM_RESULTS; i++)
  {
    variance = variance * i/(i+1) + pow(fabs(results[i] - mean), 2)/(i+1);
  }
  variance = variance * (NUM_RESULTS) / (NUM_RESULTS - 1);
  printf("Mean: %f\tError: %f\n", mean, mean - 1/(double)(LAMBDA));
  printf("Variance: %f\tError: %f\n", variance, variance - 1/((double)(LAMBDA*LAMBDA)));
}

//Problem 5) Using the random sequence generated for problem 3, simulate problem 2.
//Namely, first choose a coin from a, b, and c with probability pa, pb, and pc.
//Then simulate four coin tosses with qa, qb, and qc. Record the number of
//occurences of each seperate event. Then calculate the probability of 2 heads in
//4 throws and the probability that coin A was chosen give 2 heads in 4 throws.
void problem_5()
{
  int numberOfCoins = 3;
  int numberOfTosses = 4;
  double coinProbs[3] = {0.5, 0.75, 1};
  double headProbs[3] = {0.33, 0.25, 0.66};
  int numberOfTrials = 5000;
  int results[numberOfCoins][numberOfTosses+1];
  for(int i = 0; i < numberOfCoins; i++) {
    for(int j = 0; j < numberOfTosses + 1; j++) {
      results[i][j]=0;
    }
  }
  int coin;
  int heads;
  double seed = 1111;
  for(int i = 0; i < numberOfTrials; i++) {
    //First choose the coin.
    seed = multiplicative_congruential_method(seed);
    for(int j = 0; j < numberOfCoins; j++) {
      if((seed/M) <= coinProbs[j]) {
          coin = j;
          break;
      }
    }
    heads = 0;
    for(int j = 0; j < numberOfTosses; j++) {
      seed = multiplicative_congruential_method(seed);
      if((seed/M) <= headProbs[coin]) {
          heads++;
      }
    }
    results[coin][heads]++;
  }
/*
  int totalB = 0;
  for(int i = 0; i < numberOfCoins; i++) {
    int numberHeads = 0;
    for(int j = 0; j < numberOfTosses + 1; j++) {
      numberHeads += results[i][j];
      if(i == 1) { totalB += results[i][j] * j; }
    }
    double probOfCoin = (double)(numberHeads)/(double)(numberOfTrials);
    printf("Probability of Coin %i: %f\n", i, probOfCoin);
  }

  int totalHeads = 0;
  for(int i = 0; i < numberOfTosses + 1; i++) {
    int numberHeads = 0;
    for(int j = 0; j < numberOfCoins; j++) {
      numberHeads += results[j][i];
    }
    totalHeads += numberHeads * i;
    double probOfToss = (double)(numberHeads)/(double)(numberOfTrials);
    printf("Probability of %i tosses in 4: %f\n", i, probOfToss);
  }
  double probOfTossTot = (double)(totalHeads)/(double)(numberOfTrials * 4);
  printf("Total Probability: %f\n", probOfTossTot);
  double probOfBHeads = (double)(totalB)/(double)(totalHeads);
  printf("Total Probability of B given heads: %f\n", probOfBHeads);*/

  int twoHeads = 0;
  for(int i = 0; i < numberOfCoins; i++) {
    twoHeads+=results[i][2];
  }
  double probOfTwoHeads = (double)(twoHeads)/(double)(numberOfTrials);
  double probOfATwoHeads = (double)(results[0][2])/(double)(twoHeads);
  printf("Probability of 2 heads in 4 tosses: %f\n", probOfTwoHeads);
  printf("Probability of A given 2 heads in 4 tosses: %f\n", probOfATwoHeads);
}

int main(int argc, const char* argv[] )
{
  printf("\n");
  problem_3();
  printf("\n");
  problem_4();
  printf("\n");
  problem_5();
  printf("\n");
}
