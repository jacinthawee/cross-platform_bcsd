
int OBJ_obj2txt(char *buf,int buf_len,ASN1_OBJECT *a,int no_name)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  void *pvVar7;
  char *dst;
  char cVar8;
  uint uVar9;
  BIGNUM *a_00;
  byte *pbVar10;
  int iVar12;
  int in_GS_OFFSET;
  char *local_64;
  size_t local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined local_54 [8];
  uint local_4c;
  char local_3a [26];
  int local_20;
  byte *pbVar11;
  
  local_64 = buf;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((a == (ASN1_OBJECT *)0x0) || (pbVar10 = a->data, pbVar10 == (byte *)0x0)) {
    *buf = '\0';
    local_60 = 0;
    goto LAB_080d6bd5;
  }
  if (no_name == 0) {
    uVar9 = OBJ_obj2nid(a);
    if (uVar9 != 0) {
      if (uVar9 < 0x398) {
        iVar12 = uVar9 * 0x18;
        if (*(int *)(nid_objs + iVar12 + 8) != 0) {
          pcVar5 = *(char **)(nid_objs + iVar12 + 4);
          if (pcVar5 == (char *)0x0) {
            pcVar5 = *(char **)(nid_objs + iVar12);
LAB_080d6e95:
            if (pcVar5 == (char *)0x0) goto LAB_080d6dca;
          }
LAB_080d6e21:
          if (buf != (char *)0x0) {
            BUF_strlcpy(buf,pcVar5,buf_len);
          }
          local_60 = strlen(pcVar5);
          goto LAB_080d6bd5;
        }
        ERR_put_error(8,0x66,0x65,"obj_dat.c",0x16a);
        iVar12 = 0x14a;
LAB_080d6f9a:
        ERR_put_error(8,0x68,0x65,"obj_dat.c",iVar12);
      }
      else if (added != (_LHASH *)0x0) {
        local_58 = local_54;
        local_5c = 3;
        local_4c = uVar9;
        pvVar7 = lh_retrieve(added,&local_5c);
        if (pvVar7 == (void *)0x0) {
          ERR_put_error(8,0x66,0x65,"obj_dat.c",0x17b);
        }
        else {
          pcVar5 = *(char **)(*(int *)((int)pvVar7 + 4) + 4);
          if (pcVar5 != (char *)0x0) goto LAB_080d6e21;
        }
        if (added != (_LHASH *)0x0) {
          local_58 = local_54;
          local_5c = 3;
          local_4c = uVar9;
          pvVar7 = lh_retrieve(added,&local_5c);
          if (pvVar7 != (void *)0x0) {
            pcVar5 = **(char ***)((int)pvVar7 + 4);
            goto LAB_080d6e95;
          }
          iVar12 = 0x15b;
          goto LAB_080d6f9a;
        }
      }
    }
LAB_080d6dca:
    pbVar10 = a->data;
  }
  iVar12 = a->length;
  if (0 < iVar12) {
    bVar2 = true;
    local_60 = 0;
    a_00 = (BIGNUM *)0x0;
LAB_080d6b44:
    uVar9 = 0;
    bVar3 = false;
    pbVar11 = pbVar10;
LAB_080d6b50:
    do {
      pbVar10 = pbVar11 + 1;
      iVar12 = iVar12 + -1;
      bVar1 = *pbVar11;
      if ((iVar12 == 0) && ((char)bVar1 < '\0')) goto LAB_080d6bc0;
      pbVar11 = pbVar10;
      if (bVar3) {
        iVar4 = BN_add_word(a_00,bVar1 & 0x7f);
        if (iVar4 == 0) goto LAB_080d6bc0;
        if (-1 < (char)bVar1) goto code_r0x080d6c2f;
      }
      else {
        uVar9 = uVar9 | bVar1 & 0x7f;
        if (-1 < (char)bVar1) {
          if (!bVar2) goto LAB_080d6d5c;
          if (uVar9 < 0x50) goto LAB_080d6d19;
          uVar9 = uVar9 - 0x50;
          cVar8 = '\x02';
          goto LAB_080d6d28;
        }
        if (uVar9 < 0x2000000) {
          uVar9 = uVar9 << 7;
          goto LAB_080d6b50;
        }
        if ((a_00 == (BIGNUM *)0x0) && (a_00 = BN_new(), a_00 == (BIGNUM *)0x0)) goto LAB_080d6bd0;
        iVar4 = BN_set_word(a_00,uVar9);
        if (iVar4 == 0) goto LAB_080d6bc4;
        bVar3 = true;
      }
      iVar4 = BN_lshift(a_00,a_00,7);
      if (iVar4 == 0) goto LAB_080d6bc0;
    } while( true );
  }
  local_60 = 0;
LAB_080d6bd5:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_60;
code_r0x080d6c2f:
  if (bVar2) {
    if (uVar9 < 0x50) {
LAB_080d6d19:
      cVar8 = (char)(uVar9 / 0x28);
      uVar9 = uVar9 % 0x28;
    }
    else {
      iVar4 = BN_sub_word(a_00,0x50);
      if (iVar4 == 0) goto LAB_080d6bc0;
      cVar8 = '\x02';
    }
LAB_080d6d28:
    if ((local_64 != (char *)0x0) && (0 < buf_len)) {
      buf_len = buf_len + -1;
      *local_64 = cVar8 + '0';
      local_64 = local_64 + 1;
    }
    local_60 = local_60 + 1;
    if (!bVar3) {
LAB_080d6d5c:
      iVar4 = buf_len;
      BIO_snprintf(local_3a,0x1a,".%lu",uVar9);
      sVar6 = strlen(local_3a);
      if ((local_64 != (char *)0x0) && (0 < buf_len)) {
        BUF_strlcpy(local_64,local_3a,buf_len);
        if (buf_len < (int)sVar6) {
          buf_len = 0;
          local_64 = local_64 + iVar4;
        }
        else {
          local_64 = local_64 + sVar6;
          buf_len = buf_len - sVar6;
        }
      }
      local_60 = local_60 + sVar6;
      goto LAB_080d6ce0;
    }
  }
  pcVar5 = BN_bn2dec(a_00);
  if (pcVar5 == (char *)0x0) {
LAB_080d6bc0:
    if (a_00 != (BIGNUM *)0x0) {
LAB_080d6bc4:
      BN_free(a_00);
    }
LAB_080d6bd0:
    local_60 = 0xffffffff;
    goto LAB_080d6bd5;
  }
  sVar6 = strlen(pcVar5);
  if (local_64 != (char *)0x0) {
    dst = local_64;
    if (0 < buf_len) {
      buf_len = buf_len + -1;
      dst = local_64 + 1;
      *local_64 = '.';
    }
    BUF_strlcpy(dst,pcVar5,buf_len);
    if (buf_len < (int)sVar6) {
      local_64 = dst + buf_len;
      buf_len = 0;
    }
    else {
      local_64 = dst + sVar6;
      buf_len = buf_len - sVar6;
    }
  }
  local_60 = local_60 + 1 + sVar6;
  CRYPTO_free(pcVar5);
LAB_080d6ce0:
  bVar2 = false;
  if (iVar12 < 1) goto code_r0x080d6cf0;
  goto LAB_080d6b44;
code_r0x080d6cf0:
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
  goto LAB_080d6bd5;
}

