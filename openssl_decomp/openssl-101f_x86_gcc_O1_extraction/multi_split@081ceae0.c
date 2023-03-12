
undefined4 __regparm3 multi_split(BIO *param_1,char *param_2,_STACK **param_3)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  _STACK *st;
  int iVar4;
  undefined4 uVar5;
  BIO_METHOD *type;
  size_t __n;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  bool bVar9;
  byte bVar10;
  char local_442;
  BIO *local_438;
  char acStack_421 [1025];
  int local_20;
  
  bVar10 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar3 = strlen(param_2);
  st = sk_new_null();
  bVar1 = true;
  *param_3 = st;
  local_442 = '\0';
  local_438 = (BIO *)0x0;
  bVar2 = false;
LAB_081ceb38:
  do {
    iVar4 = BIO_gets(param_1,acStack_421 + 1,0x400);
    if (iVar4 < 1) {
      uVar5 = 0;
LAB_081cebd1:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return uVar5;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    __n = sVar3;
    if (sVar3 == 0xffffffff) {
      __n = strlen(param_2);
    }
    bVar9 = iVar4 == __n + 1;
    if ((int)(__n + 1) < iVar4) {
      iVar6 = 2;
      pcVar7 = acStack_421 + 1;
      pcVar8 = "--";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar9 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        iVar6 = strncmp(acStack_421 + 3,param_2,__n);
        bVar9 = iVar6 == 0;
        if (bVar9) {
          iVar4 = 2;
          pcVar7 = acStack_421 + __n + 3;
          pcVar8 = "--";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar7 == *pcVar8;
            pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
            pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
          } while (bVar9);
          if (bVar9) {
            sk_push(st,local_438);
            uVar5 = 1;
            goto LAB_081cebd1;
          }
          local_442 = local_442 + '\x01';
          bVar1 = true;
          goto LAB_081ceb38;
        }
      }
    }
    if (local_442 != '\0') {
      bVar9 = false;
      do {
        while (acStack_421[iVar4] != '\n') {
          if ((acStack_421[iVar4] != '\r') || (iVar4 = iVar4 + -1, iVar4 == 0)) goto LAB_081cec20;
        }
        iVar4 = iVar4 + -1;
        bVar9 = true;
      } while (iVar4 != 0);
      bVar9 = true;
LAB_081cec20:
      if (bVar1) {
        if (local_438 != (BIO *)0x0) {
          sk_push(st,local_438);
        }
        type = BIO_s_mem();
        local_438 = BIO_new(type);
        BIO_ctrl(local_438,0x82,0,(void *)0x0);
      }
      else if (bVar2) {
        BIO_write(local_438,"\r\n",2);
      }
      bVar1 = false;
      bVar2 = bVar9;
      if (iVar4 != 0) {
        BIO_write(local_438,acStack_421 + 1,iVar4);
      }
    }
  } while( true );
}

