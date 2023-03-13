
uchar * __regparm3 asn1_d2i_read_bio_constprop_0(BIO *param_1,BUF_MEM **param_2)

{
  char *pcVar1;
  BUF_MEM *str;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  ulong uVar5;
  uchar *puVar6;
  uchar *puVar7;
  uint uVar8;
  int in_GS_OFFSET;
  bool bVar9;
  uint local_68;
  int local_64;
  uint local_58;
  uchar *local_4c [3];
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34 [5];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  str = BUF_MEM_new();
  if (str != (BUF_MEM *)0x0) {
    puVar7 = (uchar *)0x0;
    ERR_clear_error();
    local_64 = 0;
    puVar4 = (uchar *)0x0;
LAB_08138e2b:
    local_68 = (int)puVar7 - (int)puVar4;
    puVar6 = puVar4;
    do {
      if (local_68 < 9) {
        puVar4 = puVar6 + 8;
        if ((puVar4 < puVar7) || (iVar2 = BUF_MEM_grow_clean(str,(size_t)puVar4), iVar2 == 0)) {
          iVar2 = 0xa8;
          goto LAB_08139017;
        }
        uVar3 = BIO_read(param_1,str->data + (int)puVar7,(int)puVar4 - (int)puVar7);
        if (((int)uVar3 < 0) && (puVar7 == puVar6)) {
          iVar2 = 0xad;
LAB_08139068:
          ERR_put_error(0xd,0x6b,0x8e,"a_d2i_fp.c",iVar2);
          goto LAB_08139030;
        }
        if (0 < (int)uVar3) {
          bVar9 = CARRY4(uVar3,(uint)puVar7);
          puVar7 = puVar7 + uVar3;
          if (!bVar9) {
            local_68 = (int)puVar7 - (int)puVar6;
            goto LAB_08138e99;
          }
          iVar2 = 0xb2;
          goto LAB_081390d8;
        }
      }
LAB_08138e99:
      pcVar1 = str->data;
      local_4c[0] = (uchar *)(pcVar1 + (int)puVar6);
      local_40 = ASN1_get_object(local_4c,(long *)local_34,&local_3c,&local_38,local_68);
      if ((local_40 & 0x80) != 0) {
        uVar5 = ERR_peek_error();
        if ((uVar5 & 0xfff) != 0x9b) goto LAB_08139030;
        ERR_clear_error();
      }
      puVar6 = local_4c[0] + ((int)puVar6 - (int)(pcVar1 + (int)puVar6));
      if ((local_40 & 1) == 0) goto LAB_08138ef8;
      local_64 = local_64 + 1;
      local_68 = (int)puVar7 - (int)puVar6;
    } while( true );
  }
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9e);
  puVar6 = (uchar *)0xffffffff;
LAB_08139041:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_08138ef8:
  if ((local_64 == 0) || (local_34[0] != 0)) {
    if ((uint)((int)puVar7 - (int)puVar6) < local_34[0]) {
      puVar4 = puVar6 + local_34[0];
      local_58 = (int)puVar4 - (int)puVar7;
      if (((int)local_58 < 0) || (puVar4 < puVar7)) {
        iVar2 = 0xe2;
        goto LAB_081390d8;
      }
      local_68 = 0x4000;
      if (local_58 != 0) {
LAB_08138f4e:
        uVar3 = local_68;
        if (local_58 <= local_68) {
          uVar3 = local_58;
        }
        iVar2 = BUF_MEM_grow_clean(str,(size_t)(puVar7 + uVar3));
        uVar8 = uVar3;
        if (iVar2 != 0) goto LAB_08138f80;
        iVar2 = 0xef;
LAB_08139017:
        ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",iVar2);
        goto LAB_08139030;
      }
    }
    else {
      puVar4 = puVar6 + local_34[0];
    }
    goto LAB_08138fd0;
  }
  puVar4 = puVar6;
  if ((local_3c != 0) || (local_64 = local_64 + -1, local_64 != 0)) goto LAB_08138e2b;
LAB_081390ad:
  if ((int)puVar6 < 0) {
    iVar2 = 0x112;
LAB_081390d8:
    ERR_put_error(0xd,0x6b,0x9b,"a_d2i_fp.c",iVar2);
LAB_08139030:
    BUF_MEM_free(str);
    puVar6 = (uchar *)0xffffffff;
  }
  else {
    *param_2 = str;
  }
  goto LAB_08139041;
LAB_08138f80:
  do {
    iVar2 = BIO_read(param_1,str->data + (int)puVar7,uVar8);
    if (iVar2 < 1) {
      iVar2 = 0xf7;
      goto LAB_08139068;
    }
    puVar7 = puVar7 + iVar2;
    uVar8 = uVar8 - iVar2;
  } while (uVar8 != 0);
  uVar8 = local_68 * 2;
  if (0x3ffffffe < local_68) {
    uVar8 = local_68;
  }
  local_58 = local_58 - uVar3;
  local_68 = uVar8;
  if (local_58 == 0) goto code_r0x08138fc0;
  goto LAB_08138f4e;
code_r0x08138fc0:
  puVar4 = puVar6 + local_34[0];
LAB_08138fd0:
  if (puVar4 < puVar6) {
    iVar2 = 0x106;
    goto LAB_081390d8;
  }
  puVar6 = puVar4;
  if (local_64 == 0) goto LAB_081390ad;
  goto LAB_08138e2b;
}

