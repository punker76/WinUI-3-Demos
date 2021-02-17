using System.Collections.Generic;

namespace VisualSorting.SortingAlgorithm
{
	public class InsertionSort : SortAlgorithmBase
	{
		/// <summary>
		/// The name of the Sortalgorithm
		/// </summary>
		public override string Caption
		{
			get { return "Insertion Sort"; }
		}

		/// <summary>
		/// Sort´s the collection
		/// </summary>
		/// <param name="input">collection to be sorted</param>
		public override void Sort(IList<int> input)
		{
			collection = new List<int>(input);
			OnReportProgress();

			for (int i = 1; i < collection.Count; i++)
			{
				int index = collection[i];
				int j = i;

				while (j > 0 && collection[j - 1].CompareTo(index) > 0)
				{
					collection[j] = collection[j - 1];
					j--;
				}
				collection[j] = index;
				OnReportProgress();
				SortCancellationToken.ThrowIfCancellationRequested();
			}
		}
	}
}
