
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  void *pvVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  ASN1_OBJECT **ppAVar7;
  char *pcVar8;
  EVP_MD *pEVar9;
  int iVar10;
  int iVar11;
  BIO *pBVar12;
  char *pcVar13;
  char *pcVar14;
  byte *pbVar15;
  byte *pbVar16;
  char *pcVar17;
  int in_GS_OFFSET;
  ASN1_VALUE *local_54;
  BIO *local_50;
  BIO *local_4c;
  undefined4 local_48;
  byte local_41 [32];
  byte local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar13 = "application/pkcs7-";
  if ((flags & 0x400U) != 0) {
    pcVar13 = "application/x-pkcs7-";
  }
  pcVar14 = "\n";
  if ((flags & 0x800U) != 0) {
    pcVar14 = "\r\n";
  }
  if (((flags & 0x40U) == 0) || (data == (BIO *)0x0)) {
    if (ctype_nid == 0x17) {
      pcVar17 = "enveloped-data";
      pcVar8 = "smime.p7m";
LAB_081cf58a:
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar14);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"%s\"%s",pcVar8,pcVar14);
      BIO_printf(bio,"Content-Type: %smime;",pcVar13);
      BIO_printf(bio," smime-type=%s;",pcVar17);
    }
    else {
      if (ctype_nid == 0x16) {
        if (econt_nid == 0xcc) {
          pcVar17 = "signed-receipt";
          pcVar8 = "smime.p7m";
        }
        else {
          pcVar17 = "signed-data";
          pcVar8 = "smime.p7m";
          iVar6 = sk_num(&mdalgs->stack);
          if (iVar6 < 0) {
            pcVar17 = "certs-only";
          }
        }
        goto LAB_081cf58a;
      }
      if (ctype_nid == 0x312) {
        pcVar17 = "compressed-data";
        pcVar8 = "smime.p7z";
        goto LAB_081cf58a;
      }
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar14);
      BIO_printf(bio,"Content-Disposition: attachment;");
      pcVar8 = "smime.p7m";
      BIO_printf(bio," filename=\"%s\"%s","smime.p7m",pcVar14);
      BIO_printf(bio,"Content-Type: %smime;",pcVar13);
    }
    pcVar13 = pcVar14;
    BIO_printf(bio," name=\"%s\"%s",pcVar8,pcVar14);
    BIO_printf(bio,"Content-Transfer-Encoding: base64%s%s",pcVar14,pcVar14);
    iVar6 = B64_write_ASN1(flags,it);
    if (iVar6 != 0) {
      BIO_printf(bio,"%s",pcVar14,pcVar13);
      iVar6 = 1;
      goto LAB_081cf3b2;
    }
  }
  else {
    iVar6 = RAND_bytes(local_41,0x20);
    pbVar15 = local_41;
    if (0 < iVar6) {
      do {
        bVar4 = *pbVar15 & 0xf;
        bVar5 = bVar4 + 0x37;
        if (bVar4 < 10) {
          bVar5 = bVar4 + 0x30;
        }
        pbVar16 = pbVar15 + 1;
        *pbVar15 = bVar5;
        pbVar15 = pbVar16;
      } while (pbVar16 != &local_21);
      local_21 = 0;
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar14);
      BIO_printf(bio,"Content-Type: multipart/signed;");
      BIO_printf(bio," protocol=\"%ssignature\";",pcVar13);
      bVar2 = false;
      BIO_puts(bio," micalg=\"");
      bVar3 = false;
      for (iVar6 = 0; iVar11 = sk_num(&mdalgs->stack), iVar6 < iVar11; iVar6 = iVar6 + 1) {
        if (bVar2) {
          BIO_write(bio,",",1);
        }
        ppAVar7 = (ASN1_OBJECT **)sk_value(&mdalgs->stack,iVar6);
        iVar11 = OBJ_obj2nid(*ppAVar7);
        pcVar8 = OBJ_nid2sn(iVar11);
        pEVar9 = EVP_get_digestbyname(pcVar8);
        if ((pEVar9 == (EVP_MD *)0x0) || (pEVar9->md_ctrl == (_func_1085 *)0x0)) {
LAB_081cf265:
          if (iVar11 == 0x2a0) {
            bVar2 = true;
            BIO_puts(bio,"sha-256");
          }
          else if (iVar11 < 0x2a1) {
            if (iVar11 == 4) {
              bVar2 = true;
              BIO_puts(bio,"md5");
            }
            else {
              if (iVar11 != 0x40) goto LAB_081cf508;
              bVar2 = true;
              BIO_puts(bio,"sha1");
            }
          }
          else if (iVar11 == 0x2a2) {
            bVar2 = true;
            BIO_puts(bio,"sha-512");
          }
          else if (iVar11 < 0x2a2) {
            bVar2 = true;
            BIO_puts(bio,"sha-384");
          }
          else {
            if (iVar11 == 0x329) {
              BIO_puts(bio,"gostr3411-94");
              break;
            }
LAB_081cf508:
            bVar2 = false;
            if (!bVar3) {
              bVar2 = true;
              BIO_puts(bio,"unknown");
              bVar3 = true;
            }
          }
        }
        else {
          iVar10 = (*pEVar9->md_ctrl)((EVP_MD_CTX *)0x0,2,0,&local_50);
          if (iVar10 < 1) {
            if (iVar10 == -2) goto LAB_081cf265;
            break;
          }
          bVar2 = true;
          BIO_puts(bio,(char *)local_50);
          CRYPTO_free(local_50);
        }
      }
      BIO_printf(bio,"\"; boundary=\"----%s\"%s%s",local_41,pcVar14,pcVar14);
      BIO_printf(bio,"This is an S/MIME signed message%s%s",pcVar14,pcVar14);
      BIO_printf(bio,"------%s%s",local_41,pcVar14);
      local_54 = val;
      if ((flags & 0x8040U) != 0x40) {
        SMIME_crlf_copy(data,bio,flags);
LAB_081cf5f7:
        BIO_printf(bio,"%s------%s%s",pcVar14,local_41,pcVar14);
        BIO_printf(bio,"Content-Type: %ssignature;",pcVar13);
        BIO_printf(bio," name=\"smime.p7s\"%s",pcVar14);
        BIO_printf(bio,"Content-Transfer-Encoding: base64%s",pcVar14);
        BIO_printf(bio,"Content-Disposition: attachment;");
        BIO_printf(bio," filename=\"smime.p7s\"%s%s",pcVar14,pcVar14);
        B64_write_ASN1(0,it);
        BIO_printf(bio,"%s------%s--%s%s",pcVar14,local_41,pcVar14,pcVar14);
        iVar6 = 1;
        goto LAB_081cf3b2;
      }
      pvVar1 = it->funcs;
      if ((pvVar1 == (void *)0x0) || (*(code **)((int)pvVar1 + 0x10) == (code *)0x0)) {
        ERR_put_error(0xd,0xd6,0xca,"asn_mime.c",0x17e);
      }
      else {
        local_50 = bio;
        local_4c = (BIO *)0x0;
        local_48 = 0;
        iVar6 = (**(code **)((int)pvVar1 + 0x10))(0xc,&local_54,it,&local_50);
        if (0 < iVar6) {
          SMIME_crlf_copy(data,local_4c,flags);
          iVar6 = (**(code **)((int)pvVar1 + 0x10))(0xd,&local_54,it,&local_50);
          while (bio != local_4c) {
            pBVar12 = BIO_pop(local_4c);
            BIO_free(local_4c);
            local_4c = pBVar12;
          }
          if (0 < iVar6) goto LAB_081cf5f7;
        }
      }
    }
  }
  iVar6 = 0;
LAB_081cf3b2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

