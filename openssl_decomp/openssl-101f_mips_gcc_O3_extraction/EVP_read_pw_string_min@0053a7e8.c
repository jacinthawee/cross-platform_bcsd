
int EVP_read_pw_string_min(char *buf,int minlen,int maxlen,char *prompt,int verify)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  char *buf_00;
  int maxlen_00;
  char *prompt_00;
  char *verify_00;
  char acStack_2024 [8192];
  char *local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(char **)PTR___stack_chk_guard_006aabf0;
  puVar4 = prompt;
  if ((prompt == (char *)0x0) && (puVar4 = prompt_string, prompt_string[0] == '\0')) {
    puVar4 = (char *)0x0;
  }
  uVar2 = (*(code *)PTR_UI_new_006a9ad4)();
  prompt_00 = (char *)0x0;
  iVar3 = 0x1fff;
  if (maxlen < 0x2000) {
    iVar3 = maxlen;
  }
  verify_00 = buf;
  (*(code *)PTR_UI_add_input_string_006a8c1c)(uVar2,puVar4,0,buf,minlen,iVar3);
  if (verify != 0) {
    verify_00 = acStack_2024;
    prompt_00 = (char *)0x0;
    (*(code *)PTR_UI_add_verify_string_006a8c28)(uVar2,puVar4,0,verify_00,minlen,iVar3,buf);
  }
  iVar3 = (*(code *)PTR_UI_process_006a8c20)(uVar2);
  (*(code *)PTR_UI_free_006a8c24)(uVar2);
  maxlen_00 = 0x2000;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(acStack_2024);
  if (local_24 != *(char **)puVar1) {
    buf_00 = local_24;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar3 = EVP_read_pw_string_min(buf_00,0,maxlen_00,prompt_00,(int)verify_00);
    return iVar3;
  }
  return iVar3;
}

