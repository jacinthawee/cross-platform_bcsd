
int X509_REQ_set_version(X509_REQ *x,long version)

{
  uchar *puVar1;
  ASN1_INTEGER *pAVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  uchar auStack_17 [7];
  int iStack_10;
  
  if (x == (X509_REQ *)0x0) {
    return 0;
  }
  pAVar2 = x->req_info->version;
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  pAVar2->type = 2;
  if (pAVar2->length < 5) {
    if (pAVar2->data != (uchar *)0x0) {
      CRYPTO_free(pAVar2->data);
    }
    puVar3 = (undefined4 *)CRYPTO_malloc(5,"a_int.c",0x164);
    pAVar2->data = (uchar *)puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      *(undefined *)(puVar3 + 1) = 0;
      goto LAB_08138524;
    }
  }
  else {
LAB_08138524:
    puVar1 = pAVar2->data;
    if (puVar1 != (uchar *)0x0) {
      if (version < 0) {
        version = -version;
        pAVar2->type = 0x102;
LAB_0813853d:
        auStack_17[2] = (uchar)version;
        if (version >> 8 == 0) {
          iVar5 = 1;
LAB_081385fd:
          iVar4 = iVar5 + -1;
          *puVar1 = auStack_17[iVar5 + 1];
          if (iVar5 != 1) {
            iVar6 = iVar5 + -3;
            pAVar2->data[1] = auStack_17[iVar5];
            if (iVar6 != -1) goto LAB_08138584;
          }
        }
        else {
          auStack_17[3] = (char)((uint)version >> 8);
          if (version >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_081385fd;
          }
          auStack_17[4] = (uchar)((uint)version >> 0x10);
          if (version >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_081385fd;
          }
          auStack_17[5] = (uchar)((uint)version >> 0x18);
          *puVar1 = auStack_17[5];
          pAVar2->data[1] = auStack_17[4];
          iVar4 = 3;
          iVar6 = 1;
LAB_08138584:
          pAVar2->data[2] = auStack_17[iVar6 + 2];
          if (iVar6 != 0) {
            pAVar2->data[3] = (uchar)version;
          }
        }
        iVar4 = iVar4 + 1;
      }
      else {
        if (version != 0) goto LAB_0813853d;
        iVar4 = 0;
      }
      pAVar2->length = iVar4;
      iVar5 = 1;
      goto LAB_081385a8;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x168);
  iVar5 = 0;
LAB_081385a8:
  if (iStack_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

