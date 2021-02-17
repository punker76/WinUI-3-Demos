using System;
using System.Collections.Generic;
using System.Linq;

namespace VisualSorting.SortingAlgorithm
{
	public class QuickSort : SortAlgorithmBase
	{
		/// <summary>
		/// The name of the Sortalgorithm
		/// </summary>
		public override string Caption
		{
			get { return "Quick Sort"; }
		}

		/// <summary>
		/// Sort´s the collection
		/// </summary>
		/// <param name="input">collection to be sorted</param>
		public override void Sort(IList<int> input)
		{
			collection = new List<int>(input);
			OnReportProgress();
			
			if(collection.Count > 1)
				QuickSortCore(collection.Min(), collection.Max());
		}

		private void QuickSortCore(int left, int right)
		{
            if (left.CompareTo(right) < 0)
			{
				int part = Separate(left, right);
				QuickSortCore(left, part - 1);
				QuickSortCore(part + 1, right);
            }
        }

		private int Separate(int left, int right)
		{
			int i = left;
			int j = right - 1;
			int pivot = collection[right];

		    do
		    {
				SortCancellationToken.ThrowIfCancellationRequested();
				while (collection[i].CompareTo(pivot) <= 0 && i.CompareTo(right) < 0)
		            i++;

                while (collection[j].CompareTo(pivot) > 0 && j.CompareTo(left) > 0)
		            j--;

                if (i.CompareTo(j) < 0)
                {
                	SwapIndex(i, j);
                    OnReportProgress();
                }
			

			} while (i.CompareTo(j) < 0);

			SwapIndex(i, right);
            OnReportProgress();

			return i;
		}
	}
}
