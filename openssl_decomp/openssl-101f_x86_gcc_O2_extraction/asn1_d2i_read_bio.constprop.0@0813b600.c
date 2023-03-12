
uchar * __regparm3 asn1_d2i_read_bio_constprop_0(BIO *param_1,BUF_MEM **param_2)

{
  char *pcVar1;
  BUF_MEM *str;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int iVar5;
  ulong uVar6;
  uint omax;
  uchar *puVar7;
  uchar *puVar8;
  int in_GS_OFFSET;
  bool bVar9;
  int local_5c;
  uchar *local_4c [3];
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34 [5];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
    puVar8 = (uchar *)0xffffffff;
  }
  else {
    puVar7 = (uchar *)0x0;
    puVar8 = (uchar *)0x0;
    ERR_clear_error();
    local_5c = 0;
    do {
      while( true ) {
        omax = (int)puVar7 - (int)puVar8;
        while( true ) {
          if (omax < 9) {
            puVar4 = puVar8 + 8;
            if ((puVar4 < puVar7) || (iVar2 = BUF_MEM_grow_clean(str,(size_t)puVar4), iVar2 == 0)) {
              iVar2 = 0xa9;
              goto LAB_0813b848;
            }
            uVar3 = BIO_read(param_1,str->data + (int)puVar7,(int)puVar4 - (int)puVar7);
            if (((int)uVar3 < 0) && (puVar7 == puVar8)) {
              iVar2 = 0xaf;
              goto LAB_0813b7b9;
            }
            if (0 < (int)uVar3) {
              bVar9 = CARRY4((uint)puVar7,uVar3);
              puVar7 = puVar7 + uVar3;
              if (bVar9) {
                iVar2 = 0xb6;
                goto LAB_0813b875;
              }
              omax = (int)puVar7 - (int)puVar8;
            }
          }
          pcVar1 = str->data;
          local_4c[0] = (uchar *)(pcVar1 + (int)puVar8);
          local_40 = ASN1_get_object(local_4c,(long *)local_34,&local_3c,&local_38,omax);
          if ((local_40 & 0x80) != 0) {
            uVar6 = ERR_peek_error();
            if ((uVar6 & 0xfff) != 0x9b) goto LAB_0813b7cf;
            ERR_clear_error();
          }
          puVar8 = local_4c[0] + ((int)puVar8 - (int)(pcVar1 + (int)puVar8));
          if ((local_40 & 1) == 0) break;
          local_5c = local_5c + 1;
          omax = (int)puVar7 - (int)puVar8;
        }
        if ((local_5c != 0) && (local_34[0] == 0)) break;
        if ((uint)((int)puVar7 - (int)puVar8) < local_34[0]) {
          puVar4 = puVar8 + local_34[0];
          iVar2 = (int)puVar4 - (int)puVar7;
          if ((iVar2 < 0) || (puVar4 < puVar7)) {
            iVar2 = 0xed;
            goto LAB_0813b875;
          }
          iVar5 = BUF_MEM_grow_clean(str,(size_t)puVar4);
          if (iVar5 == 0) {
            iVar2 = 0xf2;
LAB_0813b848:
            ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",iVar2);
            goto LAB_0813b7cf;
          }
          if (iVar2 != 0) {
LAB_0813b79a:
            iVar5 = BIO_read(param_1,str->data + (int)puVar7,iVar2);
            if (0 < iVar5) goto LAB_0813b790;
            iVar2 = 0xfb;
LAB_0813b7b9:
            ERR_put_error(0xd,0x6b,0x8e,"a_d2i_fp.c",iVar2);
            goto LAB_0813b7cf;
          }
        }
LAB_0813b82a:
        bVar9 = CARRY4(local_34[0],(uint)puVar8);
        puVar8 = puVar8 + local_34[0];
        if (bVar9) {
          iVar2 = 0x106;
          goto LAB_0813b875;
        }
        if (local_5c == 0) goto LAB_0813b72b;
      }
    } while ((local_3c != 0) || (local_5c = local_5c + -1, local_5c != 0));
LAB_0813b72b:
    if ((int)puVar8 < 0) {
      iVar2 = 0x115;
LAB_0813b875:
      ERR_put_error(0xd,0x6b,0x9b,"a_d2i_fp.c",iVar2);
LAB_0813b7cf:
      BUF_MEM_free(str);
      puVar8 = (uchar *)0xffffffff;
    }
    else {
      *param_2 = str;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0813b790:
  puVar7 = puVar7 + iVar5;
  iVar2 = iVar2 - iVar5;
  if (iVar2 == 0) goto LAB_0813b82a;
  goto LAB_0813b79a;
}

