
ASN1_VALUE * SMIME_read_ASN1(BIO *bio,BIO **bcont,ASN1_ITEM *it)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  ASN1_VALUE *pAVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ASN1_VALUE *pAVar9;
  BIO *out;
  char *pcVar10;
  char *pcVar11;
  char cVar12;
  code *pcVar13;
  BIO *pBVar14;
  BIO *pBVar15;
  char *pcVar16;
  int unaff_s1;
  char *unaff_s2;
  int unaff_s3;
  char **unaff_s7;
  code *pcVar17;
  char acStack_48e [1026];
  BIO *pBStack_8c;
  ASN1_VALUE *pAStack_88;
  int iStack_84;
  _func_603 *p_Stack_80;
  int iStack_7c;
  BIO **ppBStack_78;
  undefined *puStack_74;
  BIO *pBStack_70;
  char **ppcStack_6c;
  ASN1_ITEM *pAStack_68;
  code *pcStack_64;
  undefined4 local_50;
  undefined *local_48;
  undefined4 local_3c;
  char *local_38 [3];
  int local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_48 = &_gp;
  local_3c = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (bcont != (BIO **)0x0) {
    *bcont = (BIO *)0x0;
  }
  pAStack_88 = (ASN1_VALUE *)mime_parse_hdr(bio);
  if (pAStack_88 == (ASN1_VALUE *)0x0) {
    pcVar17 = *(code **)(local_48 + -0x6eac);
    pBVar14 = (BIO *)0xcf;
    local_50 = 0x1b2;
    goto LAB_0060cc90;
  }
  unaff_s7 = local_38;
  unaff_s2 = "content-type";
  local_38[0] = "content-type";
  iVar3 = (**(code **)(local_48 + -0x6d9c))(pAStack_88,unaff_s7);
  if ((iVar3 < 0) || (unaff_s3 = (**(code **)(local_48 + -0x7fbc))(pAStack_88,iVar3), unaff_s3 == 0)
     ) {
LAB_0060cc64:
    (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
    pBVar14 = (BIO *)0xd1;
    local_50 = 0x1b8;
    pcVar17 = *(code **)(local_48 + -0x6eac);
  }
  else {
    unaff_s1 = *(int *)(unaff_s3 + 4);
    if (unaff_s1 == 0) goto LAB_0060cc64;
    iVar3 = (**(code **)(local_48 + -0x52c8))(unaff_s1,"multipart/signed");
    if (iVar3 != 0) {
      iVar3 = (**(code **)(local_48 + -0x52c8))(unaff_s1,"application/x-pkcs7-mime");
      if ((iVar3 == 0) ||
         (iVar3 = (**(code **)(local_48 + -0x52c8))(unaff_s1,"application/pkcs7-mime"), iVar3 == 0))
      {
        (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
        uVar4 = (**(code **)(local_48 + -0x7924))();
        unaff_s1 = (**(code **)(local_48 + -0x7f3c))(uVar4);
        if (unaff_s1 == 0) {
          local_50 = 0xba;
          (**(code **)(local_48 + -0x6eac))(0xd,0xd1,0x41,"asn_mime.c");
        }
        else {
          unaff_s2 = (char *)(**(code **)(local_48 + -0x791c))(unaff_s1,bio);
          pAVar5 = (ASN1_VALUE *)(**(code **)(local_48 + -0x7268))(it,unaff_s2,0);
          if (pAVar5 != (ASN1_VALUE *)0x0) {
            pcVar16 = (char *)0x0;
            pBVar14 = (BIO *)0x0;
            pcVar13 = (code *)&DAT_0000000b;
            (**(code **)(local_48 + -0x7fc8))(unaff_s2);
            (**(code **)(local_48 + -0x7418))(unaff_s2);
            (**(code **)(local_48 + -0x7f70))(unaff_s1);
            pAStack_88 = pAVar5;
            goto LAB_0060c8cc;
          }
          local_50 = 0xc0;
          (**(code **)(local_48 + -0x6eac))(0xd,0xd1,0x6e,"asn_mime.c");
          (**(code **)(local_48 + -0x7fc8))(unaff_s2,0xb,0,0);
          (**(code **)(local_48 + -0x7418))(unaff_s2);
          (**(code **)(local_48 + -0x7f70))(unaff_s1);
        }
        pcVar16 = "asn_mime.c";
        pBVar14 = (BIO *)0xcb;
        pcVar13 = (code *)&DAT_000000d4;
        local_50 = 0x205;
        (**(code **)(local_48 + -0x6eac))(0xd);
        pAVar5 = (ASN1_VALUE *)0x0;
        pAStack_88 = (ASN1_VALUE *)0x680000;
      }
      else {
        pcVar16 = "asn_mime.c";
        local_50 = 0x1fc;
        (**(code **)(local_48 + -0x6eac))(0xd,0xd4,0xcd);
        pBVar14 = *(BIO **)(unaff_s3 + 4);
        (**(code **)(local_48 + -0x6ca4))(2,"type: ");
        pcVar13 = mime_hdr_free;
        (**(code **)(local_48 + -0x7d88))(pAStack_88);
        pAVar5 = (ASN1_VALUE *)0x0;
      }
      goto LAB_0060c8cc;
    }
    local_38[0] = "boundary";
    iVar3 = (**(code **)(local_48 + -0x6d9c))(*(undefined4 *)(unaff_s3 + 8),unaff_s7);
    if (((-1 < iVar3) &&
        (iVar3 = (**(code **)(local_48 + -0x7fbc))(*(undefined4 *)(unaff_s3 + 8),iVar3), iVar3 != 0)
        ) && (*(int *)(iVar3 + 4) != 0)) {
      unaff_s3 = multi_split(bio,*(int *)(iVar3 + 4),&local_3c);
      unaff_s1 = 0x610000;
      (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
      if ((unaff_s3 == 0) || (iVar3 = (**(code **)(local_48 + -0x7fb4))(local_3c), iVar3 != 2)) {
        pcVar17 = *(code **)(local_48 + -0x6eac);
        pBVar14 = (BIO *)0xd2;
        local_50 = 0x1c9;
LAB_0060cb48:
        pcVar16 = "asn_mime.c";
        (*pcVar17)(0xd,0xd4);
      }
      else {
        unaff_s3 = (**(code **)(local_48 + -0x7fbc))(local_3c,1);
        pAStack_88 = (ASN1_VALUE *)mime_parse_hdr(unaff_s3);
        if (pAStack_88 == (ASN1_VALUE *)0x0) {
          pcVar17 = *(code **)(local_48 + -0x6eac);
          pBVar14 = (BIO *)&DAT_000000d0;
          local_50 = 0x1d2;
          goto LAB_0060cb48;
        }
        local_38[0] = "content-type";
        iVar3 = (**(code **)(local_48 + -0x6d9c))(pAStack_88,unaff_s7);
        if (((iVar3 < 0) ||
            (bio = (BIO *)(**(code **)(local_48 + -0x7fbc))(pAStack_88,iVar3), bio == (BIO *)0x0))
           || (unaff_s2 = (char *)bio->callback, (_func_603 *)unaff_s2 == (_func_603 *)0x0)) {
          (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
          pBVar14 = (BIO *)&DAT_000000d4;
          local_50 = 0x1db;
          pcVar17 = *(code **)(local_48 + -0x6eac);
          goto LAB_0060cc90;
        }
        iVar3 = (**(code **)(local_48 + -0x52c8))(unaff_s2,"application/x-pkcs7-signature");
        if ((iVar3 == 0) ||
           (iVar3 = (**(code **)(local_48 + -0x52c8))(unaff_s2,"application/pkcs7-signature"),
           iVar3 == 0)) {
          (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
          uVar4 = (**(code **)(local_48 + -0x7924))();
          unaff_s2 = (char *)(**(code **)(local_48 + -0x7f3c))(uVar4);
          if ((_func_603 *)unaff_s2 == (_func_603 *)0x0) {
            local_50 = 0xba;
            (**(code **)(local_48 + -0x6eac))(0xd,0xd1,0x41,"asn_mime.c");
          }
          else {
            unaff_s1 = (**(code **)(local_48 + -0x791c))(unaff_s2,unaff_s3);
            pAVar5 = (ASN1_VALUE *)(**(code **)(local_48 + -0x7268))(it,unaff_s1,0);
            if (pAVar5 != (ASN1_VALUE *)0x0) {
              pcVar16 = (char *)0x0;
              pBVar14 = (BIO *)0x0;
              (**(code **)(local_48 + -0x7fc8))(unaff_s1,0xb);
              (**(code **)(local_48 + -0x7418))(unaff_s1);
              (**(code **)(local_48 + -0x7f70))(unaff_s2);
              pAStack_88 = pAVar5;
              if (bcont == (BIO **)0x0) {
                pcVar13 = *(code **)(local_48 + -0x55ec);
                (**(code **)(local_48 + -0x7d88))(local_3c);
              }
              else {
                pcVar13 = (code *)0x0;
                pBVar15 = (BIO *)(**(code **)(local_48 + -0x7fbc))(local_3c);
                pcVar17 = *(code **)(local_48 + -0x7f70);
                *bcont = pBVar15;
                (*pcVar17)(unaff_s3);
                (**(code **)(local_48 + -0x7f60))(local_3c);
              }
              goto LAB_0060c8cc;
            }
            local_50 = 0xc0;
            (**(code **)(local_48 + -0x6eac))(0xd,0xd1,0x6e,"asn_mime.c");
            (**(code **)(local_48 + -0x7fc8))(unaff_s1,0xb,0,0);
            (**(code **)(local_48 + -0x7418))(unaff_s1);
            (**(code **)(local_48 + -0x7f70))(unaff_s2);
          }
          pAStack_88 = (ASN1_VALUE *)0x680000;
          pcVar17 = *(code **)(local_48 + -0x6eac);
          pBVar14 = (BIO *)&DAT_000000cc;
          local_50 = 0x1ea;
          goto LAB_0060cb48;
        }
        pcVar16 = "asn_mime.c";
        local_50 = 0x1e1;
        (**(code **)(local_48 + -0x6eac))(0xd,0xd4,0xd5);
        pBVar14 = (BIO *)bio->callback;
        (**(code **)(local_48 + -0x6ca4))(2,"type: ");
        (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
      }
      pcVar13 = *(code **)(local_48 + -0x55ec);
      (**(code **)(local_48 + -0x7d88))(local_3c);
      pAVar5 = (ASN1_VALUE *)0x0;
      goto LAB_0060c8cc;
    }
    (**(code **)(local_48 + -0x7d88))(pAStack_88,mime_hdr_free);
    pBVar14 = (BIO *)0xd3;
    local_50 = 0x1c3;
    pcVar17 = *(code **)(local_48 + -0x6eac);
  }
LAB_0060cc90:
  pcVar16 = "asn_mime.c";
  pcVar13 = (code *)&DAT_000000d4;
  (*pcVar17)(0xd);
  pAVar5 = (ASN1_VALUE *)0x0;
LAB_0060c8cc:
  if (local_2c == *(int *)puStack_74) {
    return pAVar5;
  }
  pcStack_64 = SMIME_crlf_copy;
  iVar3 = local_2c;
  (**(code **)(local_48 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pBStack_8c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  pAVar5 = (ASN1_VALUE *)pcVar13;
  pBVar15 = pBVar14;
  iStack_84 = unaff_s1;
  p_Stack_80 = (_func_603 *)unaff_s2;
  iStack_7c = unaff_s3;
  ppBStack_78 = bcont;
  pBStack_70 = bio;
  ppcStack_6c = unaff_s7;
  pAStack_68 = it;
  uVar4 = (*(code *)PTR_BIO_f_buffer_006a7854)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (iVar6 == 0) {
    pAVar9 = (ASN1_VALUE *)0x0;
  }
  else {
    uVar4 = (*(code *)PTR_BIO_push_006a74c4)(iVar6,pcVar13);
    if (((uint)pBVar14 & 0x80) == 0) {
      if (((uint)pBVar14 & 1) != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(uVar4,"Content-Type: text/plain\r\n\r\n");
      }
      pcVar16 = acStack_48e + 2;
LAB_0060cf58:
      iVar7 = (*(code *)PTR_BIO_gets_006a74d4)(iVar3,pcVar16,0x400);
      if (0 < iVar7) {
        do {
          iVar8 = iVar7 + -1;
          pcVar10 = pcVar16 + iVar7 + -2;
          bVar1 = false;
          cVar12 = acStack_48e[iVar7 + 1];
          if (cVar12 == '\n') goto LAB_0060cfac;
          while (cVar12 == '\r') {
            iVar7 = iVar8;
            pcVar11 = pcVar10;
            if (iVar8 == 0) goto LAB_0060cfd0;
            while( true ) {
              pcVar10 = pcVar11 + -1;
              iVar8 = iVar7 + -1;
              cVar12 = *pcVar11;
              if (cVar12 != '\n') break;
LAB_0060cfac:
              bVar1 = true;
              iVar7 = iVar8;
              pcVar11 = pcVar10;
              if (iVar8 == 0) goto LAB_0060cfd8;
            }
          }
          (*(code *)PTR_BIO_write_006a6e14)(uVar4,pcVar16,iVar7);
LAB_0060cfd0:
          if (!bVar1) goto LAB_0060cf58;
LAB_0060cfd8:
          (*(code *)PTR_BIO_write_006a6e14)(uVar4,"\r\n",2);
          iVar7 = (*(code *)PTR_BIO_gets_006a74d4)(iVar3,pcVar16,0x400);
          if (iVar7 < 1) break;
        } while( true );
      }
    }
    else {
      while (iVar7 = (*(code *)PTR_BIO_read_006a74c0)(iVar3,acStack_48e + 2,0x400), 0 < iVar7) {
        (*(code *)PTR_BIO_write_006a6e14)(uVar4,acStack_48e + 2,iVar7);
      }
    }
    pcVar16 = (char *)0x0;
    pBVar15 = (BIO *)0x0;
    pAVar5 = (ASN1_VALUE *)&DAT_0000000b;
    (*(code *)PTR_BIO_ctrl_006a6e18)(uVar4);
    (*(code *)PTR_BIO_pop_006a79c8)(uVar4);
    (*(code *)PTR_BIO_free_006a6e70)(iVar6);
    pAVar9 = (ASN1_VALUE *)0x1;
  }
  if (pBStack_8c == *(BIO **)puVar2) {
    return pAVar9;
  }
  pBVar14 = pBStack_8c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((uint)pcVar16 & 0x1000) == 0) {
    (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(&_gp,pBVar14,pAVar5);
    pAVar5 = (ASN1_VALUE *)0x1;
  }
  else {
    out = BIO_new_NDEF(pBVar14,pAVar5,(ASN1_ITEM *)&_gp);
    if (out != (BIO *)0x0) {
      SMIME_crlf_copy(pBVar15,out,(int)pcVar16);
      (*(code *)PTR_BIO_ctrl_006a6e18)(out,0xb,0,0);
      do {
        pBVar15 = (BIO *)(*(code *)PTR_BIO_pop_006a79c8)(out);
        (*(code *)PTR_BIO_free_006a6e70)(out);
        out = pBVar15;
      } while (pBVar14 != pBVar15);
      return (ASN1_VALUE *)0x1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd3,0x41,"asn_mime.c",0x7d);
    pAVar5 = (ASN1_VALUE *)0x0;
  }
  return pAVar5;
}

