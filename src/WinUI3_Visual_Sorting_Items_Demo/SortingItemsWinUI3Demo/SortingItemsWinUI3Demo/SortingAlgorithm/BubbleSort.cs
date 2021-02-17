using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace VisualSorting.SortingAlgorithm
{
    public class BubbleSort : SortAlgorithmBase
    {
        /// <summary>
        /// The name of the Sortalgorithm
        /// </summary>
		public override string Caption
        {
            get { return "Bubble Sort"; }
        }

        /// <summary>
        /// Sort´s the collection
        /// </summary>
        /// <param name="input">collection to be sorted</param>
        public override void Sort(IList<int> input)
        {
            collection = new List<int>(input);
            OnReportProgress();

            for (int i = collection.Count - 1; i >= 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (collection[j - 1].CompareTo(collection[j]) > 0)
                        SwapIndex(j - 1, j);
                    SortCancellationToken.ThrowIfCancellationRequested();
                }
                OnReportProgress();

                SortCancellationToken.ThrowIfCancellationRequested();
            }
        }
    }
}
