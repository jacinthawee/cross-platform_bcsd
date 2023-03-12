
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  char *pcVar5;
  EVP_MD *pEVar6;
  int iVar7;
  int iVar8;
  BIO *pBVar9;
  byte bVar10;
  byte bVar11;
  char *pcVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  char *pcVar16;
  void *pvVar17;
  char *pcVar18;
  char cVar19;
  ASN1_VALUE *local_60;
  BIO *local_5c;
  BIO *local_58;
  undefined4 local_54;
  byte abStack_50 [32];
  byte local_30 [4];
  byte *local_2c;
  
  pbVar15 = __stack_chk_guard;
  pcVar12 = "application/x-pkcs7-";
  if ((flags & 0x400U) == 0) {
    pcVar12 = "application/pkcs7-";
  }
  pcVar18 = "\n";
  if ((flags & 0x800U) != 0) {
    pcVar18 = "\r\n";
  }
  local_2c = __stack_chk_guard;
  if (((flags & 0x40U) == 0) || (data == (BIO *)0x0)) {
    if (ctype_nid == 0x17) {
      pcVar16 = "smime.p7m";
      pcVar5 = "enveloped-data";
LAB_0010f884:
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar18);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"%s\"%s",pcVar16,pcVar18);
      BIO_printf(bio,"Content-Type: %smime;",pcVar12);
      BIO_printf(bio," smime-type=%s;",pcVar5);
    }
    else {
      if (ctype_nid == 0x16) {
        cVar19 = 0xcb < (uint)econt_nid;
        if (econt_nid == 0xcc) {
          pcVar16 = "smime.p7m";
          pcVar5 = "signed-receipt";
        }
        else {
          iVar3 = sk_num(&mdalgs->stack);
          pcVar16 = "smime.p7m";
          pcVar5 = (char *)(iVar3 >> 0x20 & 0x1753cc);
          if (cVar19 == '\0') {
            pcVar5 = "signed-data";
          }
        }
        goto LAB_0010f884;
      }
      if (ctype_nid == 0x312) {
        pcVar16 = "smime.p7z";
        pcVar5 = "compressed-data";
        goto LAB_0010f884;
      }
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar18);
      BIO_printf(bio,"Content-Disposition: attachment;");
      pcVar16 = "smime.p7m";
      BIO_printf(bio," filename=\"%s\"%s",&DAT_001753c0,pcVar18);
      BIO_printf(bio,"Content-Type: %smime;",pcVar12);
    }
    BIO_printf(bio," name=\"%s\"%s",pcVar16,pcVar18);
    BIO_printf(bio,"Content-Transfer-Encoding: base64%s%s",pcVar18,pcVar18);
    iVar3 = B64_write_ASN1(bio,val,data,flags,it);
    if (iVar3 != 0) {
      BIO_printf(bio,"%s",pcVar18);
      iVar3 = 1;
      goto LAB_0010f6ea;
    }
  }
  else {
    iVar3 = RAND_bytes(abStack_50,0x20);
    if (0 < iVar3) {
      pbVar15 = local_30;
    }
    pbVar13 = abStack_50;
    if (0 < iVar3) {
      do {
        bVar10 = *pbVar13 & 0xf;
        bVar11 = bVar10 + 0x30;
        if (9 < bVar10) {
          bVar11 = bVar10 + 0x37;
        }
        pbVar14 = pbVar13 + 1;
        *pbVar13 = bVar11;
        pbVar13 = pbVar14;
      } while (pbVar14 != pbVar15);
      bVar1 = false;
      local_30[0] = 0;
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar18);
      bVar2 = false;
      BIO_printf(bio,"Content-Type: multipart/signed;");
      BIO_printf(bio," protocol=\"%ssignature\";",pcVar12);
      BIO_puts(bio," micalg=\"");
      for (iVar3 = 0; iVar8 = sk_num(&mdalgs->stack), iVar3 < iVar8; iVar3 = iVar3 + 1) {
        if (bVar1) {
          BIO_write(bio,",",1);
        }
        ppAVar4 = (ASN1_OBJECT **)sk_value(&mdalgs->stack,iVar3);
        iVar8 = OBJ_obj2nid(*ppAVar4);
        pcVar5 = OBJ_nid2sn(iVar8);
        pEVar6 = EVP_get_digestbyname(pcVar5);
        if ((pEVar6 == (EVP_MD *)0x0) || (pEVar6->md_ctrl == (_func_1085 *)0x0)) {
LAB_0010f702:
          if (iVar8 == 0x2a0) {
            bVar1 = true;
            BIO_puts(bio,"sha-256");
          }
          else if (iVar8 < 0x2a1) {
            if (iVar8 == 4) {
              bVar1 = true;
              BIO_puts(bio,"md5");
            }
            else {
              if (iVar8 != 0x40) goto LAB_0010f842;
              bVar1 = true;
              BIO_puts(bio,"sha1");
            }
          }
          else if (iVar8 == 0x2a2) {
            bVar1 = true;
            BIO_puts(bio,"sha-512");
          }
          else if (iVar8 < 0x2a2) {
            bVar1 = true;
            BIO_puts(bio,"sha-384");
          }
          else {
            if (iVar8 == 0x329) {
              BIO_puts(bio,"gostr3411-94");
              break;
            }
LAB_0010f842:
            bVar1 = false;
            if (!bVar2) {
              bVar1 = true;
              BIO_puts(bio,"unknown");
              bVar2 = bVar1;
            }
          }
        }
        else {
          iVar7 = (*pEVar6->md_ctrl)((EVP_MD_CTX *)0x0,2,0,&local_5c);
          if (iVar7 < 1) {
            if (iVar7 == -2) goto LAB_0010f702;
            break;
          }
          BIO_puts(bio,(char *)local_5c);
          CRYPTO_free(local_5c);
          bVar1 = true;
        }
      }
      BIO_printf(bio,"\"; boundary=\"----%s\"%s%s",abStack_50,pcVar18,pcVar18);
      BIO_printf(bio,"This is an S/MIME signed message%s%s",pcVar18,pcVar18);
      BIO_printf(bio,"------%s%s",abStack_50,pcVar18);
      pvVar17 = it->funcs;
      local_60 = val;
      if ((flags & 0x8040U) != 0x40) {
        SMIME_crlf_copy(data,bio,flags);
LAB_0010f8e0:
        BIO_printf(bio,"%s------%s%s",pcVar18,abStack_50,pcVar18);
        BIO_printf(bio,"Content-Type: %ssignature;",pcVar12);
        BIO_printf(bio," name=\"smime.p7s\"%s",pcVar18);
        BIO_printf(bio,"Content-Transfer-Encoding: base64%s",pcVar18);
        BIO_printf(bio,"Content-Disposition: attachment;");
        BIO_printf(bio," filename=\"smime.p7s\"%s%s",pcVar18,pcVar18);
        B64_write_ASN1(bio,val,0,0,it);
        BIO_printf(bio,"%s------%s--%s%s",pcVar18,abStack_50,pcVar18,pcVar18);
        iVar3 = 1;
        goto LAB_0010f6ea;
      }
      if ((pvVar17 == (void *)0x0) || (*(code **)((int)pvVar17 + 0x10) == (code *)0x0)) {
        ERR_put_error(0xd,0xd6,0xca,"asn_mime.c",0x17e);
      }
      else {
        local_58 = (BIO *)0x0;
        local_54 = 0;
        local_5c = bio;
        iVar3 = (**(code **)((int)pvVar17 + 0x10))(0xc,&local_60,it,&local_5c);
        if (0 < iVar3) {
          SMIME_crlf_copy(data,local_58,flags);
          iVar3 = (**(code **)((int)pvVar17 + 0x10))(0xd,&local_60,it,&local_5c);
          while (bio != local_58) {
            pBVar9 = BIO_pop(local_58);
            BIO_free(local_58);
            local_58 = pBVar9;
          }
          if (0 < iVar3) goto LAB_0010f8e0;
        }
      }
    }
  }
  iVar3 = 0;
LAB_0010f6ea:
  if (local_2c == __stack_chk_guard) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

