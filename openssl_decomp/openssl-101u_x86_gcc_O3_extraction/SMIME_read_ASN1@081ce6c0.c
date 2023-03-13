
ASN1_VALUE * SMIME_read_ASN1(BIO *bio,BIO **bcont,ASN1_ITEM *it)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  BIO_METHOD *pBVar4;
  BIO *pBVar5;
  BIO *pBVar6;
  ASN1_VALUE *pAVar7;
  BIO *in;
  char *pcVar8;
  char *pcVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *pcVar12;
  byte *pbVar13;
  int in_GS_OFFSET;
  bool bVar14;
  bool bVar15;
  byte bVar16;
  int iVar17;
  char *local_2c [3];
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (bcont != (BIO **)0x0) {
    *bcont = (BIO *)0x0;
  }
  p_Var1 = (_STACK *)mime_parse_hdr();
  if (p_Var1 == (_STACK *)0x0) {
    iVar17 = 0x1b2;
    iVar2 = 0xcf;
  }
  else {
    local_2c[0] = "content-type";
    iVar2 = sk_find(p_Var1,local_2c);
    if (-1 < iVar2) {
      pvVar3 = sk_value(p_Var1,iVar2);
      if (pvVar3 != (void *)0x0) {
        pcVar9 = *(char **)((int)pvVar3 + 4);
        bVar14 = pcVar9 == (char *)0x0;
        if (!bVar14) {
          iVar2 = 0x11;
          pcVar8 = pcVar9;
          pcVar12 = "multipart/signed";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar14 = *pcVar8 == *pcVar12;
            pcVar8 = pcVar8 + (uint)bVar16 * -2 + 1;
            pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
          } while (bVar14);
          if (!bVar14) {
            iVar2 = 0x19;
            pcVar8 = pcVar9;
            pcVar12 = "application/x-pkcs7-mime";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar14 = *pcVar8 == *pcVar12;
              pcVar8 = pcVar8 + (uint)bVar16 * -2 + 1;
              pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
            } while (bVar14);
            if (!bVar14) {
              iVar2 = 0x17;
              pcVar8 = "application/pkcs7-mime";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar14 = *pcVar9 == *pcVar8;
                pcVar9 = pcVar9 + (uint)bVar16 * -2 + 1;
                pcVar8 = pcVar8 + (uint)bVar16 * -2 + 1;
              } while (bVar14);
              if (!bVar14) {
                ERR_put_error(0xd,0xd4,0xcd,"asn_mime.c",0x1fc);
                ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar3 + 4));
                sk_pop_free(p_Var1,mime_hdr_free);
                pAVar7 = (ASN1_VALUE *)0x0;
                goto LAB_081ce800;
              }
            }
            sk_pop_free(p_Var1,mime_hdr_free);
            pBVar4 = BIO_f_base64();
            pBVar5 = BIO_new(pBVar4);
            if (pBVar5 == (BIO *)0x0) {
              ERR_put_error(0xd,0xd1,0x41,"asn_mime.c",0xba);
            }
            else {
              pBVar6 = BIO_push(pBVar5,bio);
              pAVar7 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,pBVar6,(void *)0x0);
              if (pAVar7 != (ASN1_VALUE *)0x0) {
                BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
                BIO_pop(pBVar6);
                BIO_free(pBVar5);
                goto LAB_081ce800;
              }
              ERR_put_error(0xd,0xd1,0x6e,"asn_mime.c",0xc0);
              BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
              BIO_pop(pBVar6);
              BIO_free(pBVar5);
            }
            iVar17 = 0x205;
            iVar2 = 0xcb;
            goto LAB_081cead0;
          }
          local_2c[0] = "boundary";
          iVar2 = sk_find(*(_STACK **)((int)pvVar3 + 8),local_2c);
          if (-1 < iVar2) {
            pvVar3 = sk_value(*(_STACK **)((int)pvVar3 + 8),iVar2);
            if ((pvVar3 != (void *)0x0) && (*(int *)((int)pvVar3 + 4) != 0)) {
              iVar2 = multi_split();
              sk_pop_free(p_Var1,mime_hdr_free);
              if (iVar2 == 0) {
LAB_081ce9f0:
                iVar17 = 0x1c9;
                iVar2 = 0xd2;
LAB_081cea02:
                ERR_put_error(0xd,0xd4,iVar2,"asn_mime.c",iVar17);
              }
              else {
                iVar2 = sk_num((_STACK *)0x0);
                if (iVar2 != 2) goto LAB_081ce9f0;
                pBVar5 = (BIO *)sk_value((_STACK *)0x0,1);
                p_Var1 = (_STACK *)mime_parse_hdr();
                if (p_Var1 == (_STACK *)0x0) {
                  iVar17 = 0x1d2;
                  iVar2 = 0xd0;
                  goto LAB_081cea02;
                }
                local_2c[0] = "content-type";
                iVar2 = sk_find(p_Var1,local_2c);
                if (iVar2 < 0) {
LAB_081cec40:
                  sk_pop_free(p_Var1,mime_hdr_free);
                  iVar17 = 0x1db;
                  iVar2 = 0xd4;
                  goto LAB_081cead0;
                }
                pvVar3 = sk_value(p_Var1,iVar2);
                if (pvVar3 == (void *)0x0) goto LAB_081cec40;
                pbVar11 = *(byte **)((int)pvVar3 + 4);
                bVar14 = false;
                bVar15 = pbVar11 == (byte *)0x0;
                if (bVar15) goto LAB_081cec40;
                iVar2 = 0x1e;
                pbVar10 = pbVar11;
                pbVar13 = (byte *)"application/x-pkcs7-signature";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar14 = *pbVar10 < *pbVar13;
                  bVar15 = *pbVar10 == *pbVar13;
                  pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                  pbVar13 = pbVar13 + (uint)bVar16 * -2 + 1;
                } while (bVar15);
                bVar14 = (!bVar14 && !bVar15) == bVar14;
                if (bVar14) {
LAB_081ce93c:
                  sk_pop_free(p_Var1,mime_hdr_free);
                  pBVar4 = BIO_f_base64();
                  pBVar6 = BIO_new(pBVar4);
                  if (pBVar6 == (BIO *)0x0) {
                    ERR_put_error(0xd,0xd1,0x41,"asn_mime.c",0xba);
                  }
                  else {
                    in = BIO_push(pBVar6,pBVar5);
                    pAVar7 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,in,(void *)0x0);
                    if (pAVar7 != (ASN1_VALUE *)0x0) {
                      BIO_ctrl(in,0xb,0,(void *)0x0);
                      BIO_pop(in);
                      BIO_free(pBVar6);
                      if (bcont == (BIO **)0x0) {
                        sk_pop_free((_STACK *)0x0,BIO_vfree);
                      }
                      else {
                        pBVar6 = (BIO *)sk_value((_STACK *)0x0,0);
                        *bcont = pBVar6;
                        BIO_free(pBVar5);
                        sk_free((_STACK *)0x0);
                      }
                      goto LAB_081ce800;
                    }
                    ERR_put_error(0xd,0xd1,0x6e,"asn_mime.c",0xc0);
                    BIO_ctrl(in,0xb,0,(void *)0x0);
                    BIO_pop(in);
                    BIO_free(pBVar6);
                  }
                  iVar17 = 0x1ea;
                  iVar2 = 0xcc;
                  goto LAB_081cea02;
                }
                iVar2 = 0x1c;
                pbVar10 = (byte *)"application/pkcs7-signature";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar14 = *pbVar11 == *pbVar10;
                  pbVar11 = pbVar11 + (uint)bVar16 * -2 + 1;
                  pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                } while (bVar14);
                if (bVar14) goto LAB_081ce93c;
                ERR_put_error(0xd,0xd4,0xd5,"asn_mime.c",0x1e1);
                ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar3 + 4));
                sk_pop_free(p_Var1,mime_hdr_free);
              }
              sk_pop_free((_STACK *)0x0,BIO_vfree);
              pAVar7 = (ASN1_VALUE *)0x0;
              goto LAB_081ce800;
            }
          }
          sk_pop_free(p_Var1,mime_hdr_free);
          iVar17 = 0x1c3;
          iVar2 = 0xd3;
          goto LAB_081cead0;
        }
      }
    }
    sk_pop_free(p_Var1,mime_hdr_free);
    iVar17 = 0x1b8;
    iVar2 = 0xd1;
  }
LAB_081cead0:
  ERR_put_error(0xd,0xd4,iVar2,"asn_mime.c",iVar17);
  pAVar7 = (ASN1_VALUE *)0x0;
LAB_081ce800:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

