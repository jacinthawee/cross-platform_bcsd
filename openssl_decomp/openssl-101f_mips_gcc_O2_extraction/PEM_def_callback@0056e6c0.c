
int PEM_def_callback(char *buf,int num,int w,void *key)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if (key == (void *)0x0) {
    pcVar3 = (char *)(*(code *)PTR_EVP_get_pw_prompt_006a9f4c)();
    puVar1 = PTR_stderr_006aac00;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "Enter PEM pass phrase:";
    }
    while( true ) {
      iVar4 = (*(code *)PTR_EVP_read_pw_string_min_006a9f50)(buf,4,num,pcVar3,w);
      if (iVar4 != 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(9,100,0x6d,"pem_lib.c",0x6f);
        (*(code *)PTR_memset_006aab00)(buf,0,num);
        return -1;
      }
      iVar4 = (*(code *)PTR_strlen_006aab30)(buf);
      if (3 < iVar4) break;
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)puVar1,1,"phrase is too short, needs to be at least %d chars\n",4);
    }
  }
  else {
    iVar2 = (*(code *)PTR_strlen_006aab30)(key);
    iVar4 = num;
    if (iVar2 <= num) {
      iVar4 = iVar2;
    }
    (*(code *)PTR_memcpy_006aabf4)(buf,key,iVar4);
  }
  return iVar4;
}

