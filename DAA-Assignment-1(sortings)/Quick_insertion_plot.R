library(ggplot2)

QuickSort <- c(0.000002,0.000003,0.000004,0.000007,0.000012,0.000008)
InsertionSort <- c(0.000001, 0.000001,0.000001,0.000001,0.000002,0.000001)
x <- c(5,10,50,90,95,100)

library(ggplot2)
ggplot(data.frame(x, MergeSort, InsertionSort), aes(x)) +
  geom_line(aes(y = MergeSort, color = "QuickSort")) +
  geom_line(aes(y = InsertionSort, color = "InsertionSort")) +
  scale_y_log10() +
  labs(x = "Input Size", y = "Seconds (log scale)",
       color = "Sorting Algorithm")
