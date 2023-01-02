#include <stdio.h>
#include <string.h>

int main(void) {
  
  char in1[80],in2[80];  //in[80]用來裝輸入檔名的陣列 
  
  printf("注意事項:\n");
  printf("1.請放在與本程式同目錄\n");
  printf("2.需輸入副檔名Ex:test.cpp\n");
  printf("請輸入第一個檔案名稱:");
  scanf("%s",&in1);  // 要讀取第一個的文件名輸入 
  printf("請輸入第二個檔案名稱:");
  scanf("%s",&in2);  // 要讀取第二個的文件名輸入 
  char *keywords[] = {"int", "char", "float","include","for","while"};  // 關鍵字列表
  
  int keyword_counts1[6] = {0},keyword_counts2[6] = {0};  // 用來記錄每個關鍵字出現的次數
  char line1[1024],line2[1024];  // line[1024]拿來裝程式碼的

  FILE *fp1 = fopen(in1, "r");  // 打開文件 
  if (fp1 == NULL) 
  {
    printf("無法打開文件 %s\n", in1);
    return 0;
  }

    while (fgets(line1, sizeof(line1), fp1) != NULL) // 逐行讀取文件中的內容
  {
    
    for (int i = 0; i < 6; i++) // 逐個關鍵字檢查是否出現在讀取到的行中
	{
     
      if (strstr(line1, keywords[i]) != NULL)  // 如果出現，就把計數器加 1，strstr指令為：第一項為被搜尋項，第二項為關鍵詞 
	  {
        keyword_counts1[i]++;
      }
    }
  }

    fclose(fp1);  // 關閉文件
  
  FILE *fp2 = fopen(in2, "r");  // 打開文件 
  if (fp2 == NULL) 
  {
    printf("無法打開文件 %s\n", in2);
    return 0;
  }

    while (fgets(line2, sizeof(line2), fp2) != NULL) // 逐行讀取文件中的內容
  {
    
    for (int j = 0; j < 6; j++) // 逐個關鍵字檢查是否出現在讀取到的行中
	{
     
      if (strstr(line2, keywords[j]) != NULL)  // 如果出現，就把計數器加 1，strstr指令為：第一項為被搜尋項，第二項為關鍵詞 
	  {
        keyword_counts2[j]++;
      }
    }
  }

    fclose(fp2);  // 關閉文件
  
  
  printf("在第一個文件 %s 中，int 共出現 %d 次，char 共出現 %d 次，float 共出現 %d 次，include 共出現 %d 次，for 共出現 %d 次，while 共出現 %d 次\n",
         in1, keyword_counts1[0], keyword_counts1[1], keyword_counts1[2],keyword_counts1[3],keyword_counts1[4],keyword_counts1[5]);  // 印出結果
         
  printf("\n");   
      
  printf("在第二個文件 %s 中，int 共出現 %d 次，char 共出現 %d 次，float 共出現 %d 次，include 共出現 %d 次，for 共出現 %d 次，while 共出現 %d 次\n",
         in2, keyword_counts2[0], keyword_counts2[1], keyword_counts2[2],keyword_counts2[3],keyword_counts2[4],keyword_counts2[5]);  // 印出結果

  return 0;
}
