using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MSDNCppDocFixer
{
	class Program
	{
		static void Main(string[] args)
		{
			string dir = @"E:\GS2018\E\Yang\Program\Git\GitYang\cpp-docs.zh-tw\docs";
			//var files = Directory.GetFiles(dir);
			

			List<string> fs = new List<string>();
			GetAllFilesInAllSubFolderToLs(dir, ref fs);
			foreach (var file in fs)
			{
				string content = File.ReadAllText(file);
				if (content.Contains("ms.translationtype: HT") && content.Contains("****"))
					Console.WriteLine(file);
			}


			string filepath =
				@"E:\GS2018\E\Yang\Program\Git\GitYang\cpp-docs.zh-tw\docs\windows\walkthrough-creating-a-standard-cpp-program-cpp.md";
			


			Console.WriteLine("ok");
			Console.Read(); 

		}

		public static void GetAllFilesInAllSubFolderToLs(string FolderPath, ref List<string> RecordNameLs)
		{
			
			string[] fileEntries = Directory.GetFiles(FolderPath);
			RecordNameLs.AddRange(fileEntries);

			string[] subdirectoryEntries = Directory.GetDirectories(FolderPath);
			foreach (string subdirectory in subdirectoryEntries)
				GetAllFilesInAllSubFolderToLs(subdirectory, ref RecordNameLs);
		}


		public static void Process(string filepath)
		{
			string content =
				File.ReadAllText(filepath);

			int index = 0;
			while (true)
			{
				index = content.IndexOf("]****", index);
				if (index < 0)
					break;
				content = content.Remove(index + 3, 2);

				int pStart = 0;
				for (int i = index - 1; i >= 0; i--)
				{
					if (content[i] == '[')
					{
						pStart = i;
						content = content.Insert(i, "**");
						break;
					}
				}

				index += 3;
			}

			index = 0;
			while (true)
			{
				index = content.IndexOf("] ****", index);
				if (index < 0)
					break;
				content = content.Remove(index + 4, 2);
				content = content.Remove(index + 1, 1);

				int pStart = 0;
				for (int i = index - 1; i >= 0; i--)
				{
					if (content[i] == '[')
					{
						pStart = i;
						content = content.Insert(i, "**");
						break;
					}
				}

				index += 3;
			}




			File.WriteAllText(filepath, content);



		}

	}
}
