using System;
using System.Collections.Generic;
using System.Linq;

namespace VisualSorting.SortingAlgorithm
{
	public class MergeSort : SortAlgorithmBase
	{
		/// <summary>
		/// The name of the Sortalgorithm
		/// </summary>
		public override string Caption
		{
			get { return "Merge Sort"; }
		}

		/// <summary>
		/// Sort´s the collection
		/// </summary>
		/// <param name="input">collection to be sorted</param>
		public override void Sort(IList<int> input)
		{
			collection = new List<int>(input);
			OnReportProgress();
			MergeSortCore(collection.ToArray(), 0, collection.Count - 1);
		}

		private void MergeSortCore(int[] data, int left, int right)
		{
			if (left.CompareTo(right) < 0)
			{
				int middle = (left + right) / 2;
				MergeSortCore(data, left, middle);
				MergeSortCore(data, middle + 1, right);
				Merge(data, left, middle, middle + 1, right);
			}
		}

		private void Merge(int[] data, int left, int middle, int middle1, int right)
		{
			int oldPosition = left;
			int size = right - left + 1;
			int[] tmpData = new int[size];
			int i = 0;

			while (left.CompareTo(middle) <= 0 && middle1.CompareTo(right) <= 0)
			{
				if (data[left].CompareTo(data[middle1]) <= 0)
					tmpData[i++] = data[left++];
				else
					tmpData[i++] = data[middle1++];
				SortCancellationToken.ThrowIfCancellationRequested();
			}

			if (left.CompareTo(middle) > 0)
			{
				for (int j = middle1; j <= right; j++)
					tmpData[i++] = data[middle1++];
			}
			else
			{
				for (int j = left; j <= middle; j++)
					tmpData[i++] = data[left++];
			}
			Array.Copy(tmpData, 0, data, oldPosition, size);
			OnReportProgress(data);
			SortCancellationToken.ThrowIfCancellationRequested();
		}
	}
}
