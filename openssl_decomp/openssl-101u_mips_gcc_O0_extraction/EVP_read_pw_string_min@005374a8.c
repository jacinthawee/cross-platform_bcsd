
int EVP_read_pw_string_min(char *buf,int minlen,int maxlen,char *prompt,int verify)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *buf_00;
  int iVar5;
  char *prompt_00;
  char acStack_2024 [8192];
  char *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(char **)PTR___stack_chk_guard_006a9ae8;
  puVar4 = prompt;
  if ((prompt == (char *)0x0) && (puVar4 = prompt_string, prompt_string[0] == '\0')) {
    puVar4 = (char *)0x0;
  }
  iVar5 = minlen;
  prompt_00 = (char *)maxlen;
  iVar2 = (*(code *)PTR_UI_new_006a89b4)();
  if (iVar2 == 0) {
    iVar3 = -1;
  }
  else {
    if (0x1fff < maxlen) {
      maxlen = 0x1fff;
    }
    prompt_00 = (char *)0x0;
    prompt = buf;
    (*(code *)PTR_UI_add_input_string_006a7b30)(iVar2,puVar4,0,buf,minlen,maxlen);
    if (verify != 0) {
      prompt = acStack_2024;
      prompt_00 = (char *)0x0;
      (*(code *)PTR_UI_add_verify_string_006a7b3c)(iVar2,puVar4,0,prompt,minlen,maxlen,buf);
    }
    iVar3 = (*(code *)PTR_UI_process_006a7b34)(iVar2);
    (*(code *)PTR_UI_free_006a7b38)(iVar2);
    iVar5 = 0x2000;
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(acStack_2024);
  }
  if (local_24 != *(char **)puVar1) {
    buf_00 = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar5 = EVP_read_pw_string_min(buf_00,0,iVar5,prompt_00,(int)prompt);
    return iVar5;
  }
  return iVar3;
}

