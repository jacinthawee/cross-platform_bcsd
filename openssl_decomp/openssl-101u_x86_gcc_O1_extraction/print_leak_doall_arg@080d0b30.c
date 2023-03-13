
void __regparm3 print_leak_doall_arg(BIO **param_1,BIO **param_2)

{
  size_t sVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  tm *ptVar7;
  int iVar8;
  undefined4 *buf;
  char *pcVar9;
  BIO *pBVar10;
  int in_GS_OFFSET;
  bool bVar11;
  CRYPTO_THREADID *id;
  int local_430;
  CRYPTO_THREADID local_428;
  undefined4 local_420;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*param_1 != *param_2) {
    if (((byte)options & 1) == 0) {
      buf = &local_420;
      sVar1 = 0x400;
    }
    else {
      ptVar7 = localtime((time_t *)(param_1 + 7));
      BIO_snprintf((char *)&local_420,0x400,"[%02d:%02d:%02d] ",ptVar7->tm_hour,ptVar7->tm_min,
                   ptVar7->tm_sec);
      puVar6 = &local_420;
      do {
        puVar5 = puVar6;
        uVar3 = *puVar5 + 0xfefefeff & ~*puVar5;
        uVar4 = uVar3 & 0x80808080;
        puVar6 = puVar5 + 1;
      } while (uVar4 == 0);
      bVar11 = (uVar3 & 0x8080) == 0;
      if (bVar11) {
        uVar4 = uVar4 >> 0x10;
      }
      if (bVar11) {
        puVar6 = (uint *)((int)puVar5 + 6);
      }
      pcVar9 = (char *)((int)puVar6 +
                       ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)&local_420));
      buf = (undefined4 *)((int)&local_420 + (int)pcVar9);
      sVar1 = 0x400 - (int)pcVar9;
    }
    pBVar10 = param_1[3];
    BIO_snprintf((char *)buf,sVar1,"%5lu file=%s, line=%d, ",param_1[6],param_1[2],pBVar10);
    sVar1 = strlen((char *)buf);
    pcVar9 = (char *)((int)buf + sVar1);
    if (((byte)options & 2) != 0) {
      id = (CRYPTO_THREADID *)(param_1 + 4);
      uVar2 = CRYPTO_THREADID_hash(id);
      BIO_snprintf(pcVar9,(int)&local_20 - (int)pcVar9,"thread=%lu, ",uVar2,id,pBVar10);
      sVar1 = strlen(pcVar9);
      pcVar9 = pcVar9 + sVar1;
    }
    BIO_snprintf(pcVar9,(int)&local_20 - (int)pcVar9,"number=%d, address=%08lX\n",param_1[1],
                 *param_1,pBVar10);
    BIO_puts(*param_2,(char *)&local_420);
    param_2[1] = (BIO *)((int)&param_2[1]->method + 1);
    param_2[2] = (BIO *)((int)&param_1[1]->method + (int)&param_2[2]->method);
    pBVar10 = param_1[8];
    if (pBVar10 != (BIO *)0x0) {
      CRYPTO_THREADID_cpy(&local_428,(CRYPTO_THREADID *)pBVar10);
      local_430 = 0;
      do {
        local_430 = local_430 + 1;
        __memset_chk(&local_420,0x3e,local_430,0x400);
        iVar8 = pBVar10->init;
        pcVar9 = pBVar10->cb_arg;
        uVar2 = CRYPTO_THREADID_hash((CRYPTO_THREADID *)pBVar10);
        BIO_snprintf((char *)((int)&local_420 + local_430),0x400 - local_430,
                     " thread=%lu, file=%s, line=%d, info=\"",uVar2,pcVar9,iVar8);
        puVar6 = &local_420;
        do {
          puVar5 = puVar6;
          uVar3 = *puVar5 + 0xfefefeff & ~*puVar5;
          uVar4 = uVar3 & 0x80808080;
          puVar6 = puVar5 + 1;
        } while (uVar4 == 0);
        bVar11 = (uVar3 & 0x8080) == 0;
        if (bVar11) {
          uVar4 = uVar4 >> 0x10;
        }
        if (bVar11) {
          puVar6 = (uint *)((int)puVar5 + 6);
        }
        pcVar9 = (char *)pBVar10->shutdown;
        iVar8 = (int)puVar6 + ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)&local_420);
        sVar1 = strlen(pcVar9);
        if ((int)(0x7dU - iVar8) < (int)sVar1) {
          memcpy((void *)(iVar8 + (int)&local_420),pcVar9,0x7dU - iVar8);
          sVar1 = 899;
          iVar8 = 0x7d;
        }
        else {
          BUF_strlcpy((char *)(iVar8 + (int)&local_420),pcVar9,0x400 - iVar8);
          puVar6 = &local_420;
          do {
            puVar5 = puVar6;
            uVar3 = *puVar5 + 0xfefefeff & ~*puVar5;
            uVar4 = uVar3 & 0x80808080;
            puVar6 = puVar5 + 1;
          } while (uVar4 == 0);
          bVar11 = (uVar3 & 0x8080) == 0;
          if (bVar11) {
            uVar4 = uVar4 >> 0x10;
          }
          if (bVar11) {
            puVar6 = (uint *)((int)puVar5 + 6);
          }
          iVar8 = (int)puVar6 + ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)&local_420);
          sVar1 = 0x400 - iVar8;
        }
        BIO_snprintf((char *)(iVar8 + (int)&local_420),sVar1,"\"\n");
        BIO_puts(*param_2,(char *)&local_420);
        pBVar10 = (BIO *)pBVar10->flags;
        if (pBVar10 == (BIO *)0x0) break;
        iVar8 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)pBVar10,&local_428);
      } while (iVar8 == 0);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

