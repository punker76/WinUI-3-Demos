using System;
using System.Collections.Generic;

namespace VisualSorting.SortingAlgorithm
{
    public class SelectionSort : SortAlgorithmBase
    {
        /// <summary>
        /// The name of the Sortalgorithm
        /// </summary>
		public override string Caption
        {
            get { return "Selection Sort"; }
        }

        /// <summary>
        /// Sort´s the collection
        /// </summary>
        /// <param name="input">collection to be sorted</param>
		public override void Sort(IList<int> input)
        {
            collection = new List<int>(input);
            OnReportProgress();

            for (int i = 0; i < collection.Count -1; i++)
            {
                int minimum = i;
                for(int j = i + 1; j < collection.Count; j++)
                {
                    if (collection[j].CompareTo(collection[minimum])  < 0)
                        minimum = j;
                    SortCancellationToken.ThrowIfCancellationRequested();
                }

            	SwapIndex(minimum, i);
                OnReportProgress();
            }
        }
    }
}
