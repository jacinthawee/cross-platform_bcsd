
UI_METHOD * UI_create_method(char *name)

{
  char **ppcVar1;
  char *pcVar2;
  uint uVar3;
  
  ppcVar1 = (char **)CRYPTO_malloc(0x1c,"ui_lib.c",0x24e);
  if (ppcVar1 != (char **)0x0) {
    *ppcVar1 = (char *)0x0;
    ppcVar1[6] = (char *)0x0;
    uVar3 = 0;
    do {
      *(undefined4 *)(((uint)(ppcVar1 + 1) & 0xfffffffc) + uVar3) = 0;
      uVar3 = uVar3 + 4;
    } while (uVar3 < ((int)ppcVar1 + (0x1c - ((uint)(ppcVar1 + 1) & 0xfffffffc)) & 0xfffffffc));
    pcVar2 = BUF_strdup(name);
    *ppcVar1 = pcVar2;
  }
  return (UI_METHOD *)ppcVar1;
}

