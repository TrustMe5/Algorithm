归并的思想

有一种排序的方法是归并排序，归并排序的主要思想是将整个序列分成两部分，分别递归将这两部分排好序之后，再和并为一个有序的序列，核心代码如下

MergeSort(first,last)

{

    If(first==last)

    return

    Int med=(first+last)/2;

    MergeSort(first,med);

    MergeSort(med+1,last);

    Merge(first,last);


}

在合并的过程中是将两个相邻并且有序的序列合并成一个有序序列，如以下两个有序序列

Seq1：3  4  5

Seq2：2  6  8  9

合并成一个有序序:

    Seq：2  3  4  5  6  8  9

    对于序列seq1中的某个数a[i],序列seq2中的某个数a[j]，如果a[i]<a[j],没有逆序数，如果a[i]>a[j]，那么逆序数为seq1中a[i]后边元素的个数(包括a[i])，即len1-i+1,

    这样累加每次递归过程的逆序数，在完成整个递归过程之后，最后的累加和就是逆序的总数
