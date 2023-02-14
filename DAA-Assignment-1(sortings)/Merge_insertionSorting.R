library(ggplot2)

MergeSort <- c(0.000003,0.000002,0.000011,0.000013, 0.000021,0.000022)
InsertionSort <- c(0.000002,0.000001,0.000002,0.000001,0.000002,0.000002)
x <- c(5,10,50,90,95,100)

library(ggplot2)
ggplot(data.frame(x, MergeSort, InsertionSort), aes(x)) +
  geom_line(aes(y = MergeSort, color = "MergeSort")) +
  geom_line(aes(y = InsertionSort, color = "InsertionSort")) +
  scale_y_log10() +
  labs(x = "Input Size", y = "Seconds (log scale)",
       color = "Sorting Algorithm")