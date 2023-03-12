
undefined4 old_entry_print(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  undefined *puVar11;
  char *pcVar12;
  int iVar13;
  undefined local_40 [28];
  int *local_24;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar1 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)();
  puVar2 = local_40;
  iVar1 = 0x16 - iVar1;
  puVar11 = puVar2;
  if (0 < iVar1) {
    puVar2 = (undefined *)(*(code *)PTR_memset_006a99f4)(puVar2,0x20,iVar1);
    puVar11 = puVar2 + iVar1;
  }
  puVar11[1] = 0;
  *puVar11 = 0x3a;
  (*(code *)PTR_BIO_puts_006a6f58)(param_1,puVar2);
  piVar6 = (int *)param_3[1];
  if (piVar6 == (int *)&DAT_00000013) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"PRINTABLE:\'");
  }
  else if (piVar6 == (int *)&DAT_00000014) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"T61STRING:\'");
  }
  else if (piVar6 == (int *)&DAT_00000016) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"IA5STRING:\'");
  }
  else if (piVar6 == (int *)0x1c) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"UNIVERSALSTRING:\'");
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"ASN.1 %2d:\'");
  }
  pcVar12 = (char *)param_3[2];
  pcVar10 = pcVar12 + *param_3;
  if (0 < *param_3) {
    do {
      while (piVar6 = (int *)(int)*pcVar12, ((uint)(piVar6 + -8) & 0xff) < 0x5f) {
        pcVar12 = pcVar12 + 1;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%c");
        if (pcVar12 == pcVar10) goto LAB_0042fb74;
      }
      if ((int)piVar6 < 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"\\0x%02X");
      }
      else {
        piVar6 = piVar6 + 0x10;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,&DAT_006353b4);
      }
      pcVar12 = pcVar12 + 1;
    } while (pcVar12 != pcVar10);
  }
LAB_0042fb74:
  puVar5 = (undefined4 *)0x63a5e4;
  (*(code *)PTR_BIO_printf_006a6e38)(param_1);
  if (local_24 == *(int **)puVar3) {
    return 1;
  }
  piVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = (undefined *)(*(code *)PTR_BUF_strdup_006a6fdc)(&_gp);
  if (puVar3 == (undefined *)0x0) {
    iVar1 = 0;
    iVar13 = 0;
    uVar8 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"memory allocation failure\n");
    goto joined_r0x00430004;
  }
  puVar2 = (undefined *)(*(code *)PTR_strchr_006a9a28)(puVar3,0x2c);
  puVar11 = PTR_strchr_006a9a28;
  if (puVar2 == (undefined *)0x0) {
    puVar11 = (undefined *)0x0;
    if (piVar4 != (int *)0x0) {
      puVar7 = (undefined *)0x0;
      goto LAB_0042fcf8;
    }
LAB_0042ff44:
    iVar1 = 0;
    iVar13 = 0;
    uVar8 = 0xffffffff;
    goto LAB_0042ff50;
  }
  puVar7 = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = (undefined *)(*(code *)puVar11)(puVar7,0x2c);
  if (puVar2 == (undefined *)0x0) {
    puVar11 = (undefined *)0x0;
  }
  else {
    puVar11 = puVar2 + 1;
    *puVar2 = 0;
  }
  if (piVar4 != (int *)0x0) {
LAB_0042fcf8:
    iVar1 = (*(code *)PTR_ASN1_UTCTIME_new_006a7030)();
    *piVar4 = iVar1;
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_ASN1_UTCTIME_set_string_006a7034)(iVar1,puVar3);
      if (iVar1 != 0) {
        if (puVar7 == (undefined *)0x0) goto LAB_0042ff44;
        goto LAB_0042fd30;
      }
      pcVar10 = "invalid revocation date %s\n";
      puVar7 = puVar3;
LAB_0042fe70:
      iVar1 = 0;
      iVar13 = 0;
      uVar8 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar10,puVar7);
      goto LAB_0042fe8c;
    }
    pcVar10 = "memory allocation failure\n";
    goto LAB_0042ffc0;
  }
LAB_0042fd30:
  iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"unspecified");
  if (iVar1 == 0) {
    uVar8 = 0;
    iVar1 = 0;
    iVar13 = 0;
LAB_0042ff50:
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = uVar8;
    }
    if (param_4 == (int *)0x0) {
      uVar8 = 1;
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar1);
    }
    else {
      *param_4 = iVar1;
      uVar8 = 1;
    }
  }
  else {
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"keyCompromise");
    if (iVar1 == 0) {
      uVar8 = 1;
      iVar1 = 0;
      iVar13 = 0;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"CACompromise");
    if (iVar1 == 0) {
      uVar8 = 2;
      iVar1 = 0;
      iVar13 = 0;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"affiliationChanged");
    if (iVar1 == 0) {
      uVar8 = 3;
      iVar1 = 0;
      iVar13 = 0;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"superseded");
    if (iVar1 == 0) {
      uVar8 = 4;
      iVar1 = 0;
      iVar13 = 0;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"cessationOfOperation");
    if (iVar1 == 0) {
      uVar8 = 5;
      iVar1 = 0;
      iVar13 = 0;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"certificateHold");
    if (iVar1 == 0) {
      uVar8 = 6;
      iVar1 = 0;
      iVar13 = 0;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"removeFromCRL");
    if (iVar1 == 0) {
      iVar1 = 0;
      iVar13 = 0;
      uVar8 = 8;
      goto LAB_0042ff50;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"holdInstruction");
    if (iVar1 == 0) {
      if (puVar11 == (undefined *)0x0) {
        pcVar10 = "missing hold instruction\n";
        goto LAB_0042ffc0;
      }
      iVar13 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar11,0);
      if (iVar13 != 0) {
        if (piVar6 == (int *)0x0) {
          iVar1 = 0;
          uVar8 = 6;
        }
        else {
          *piVar6 = iVar13;
          iVar1 = 0;
          uVar8 = 6;
        }
        goto LAB_0042ff50;
      }
      iVar1 = 0;
      uVar8 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"invalid object identifier %s\n",puVar11);
    }
    else {
      iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"keyTime");
      if (iVar1 == 0) {
        iVar9 = 9;
      }
      else {
        iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(puVar7,"CAkeyTime");
        if (iVar1 != 0) {
          pcVar10 = "invalid reason code %s\n";
          goto LAB_0042fe70;
        }
        iVar9 = 10;
      }
      if (puVar11 == (undefined *)0x0) {
        pcVar10 = "missing compromised time\n";
LAB_0042ffc0:
        iVar1 = 0;
        iVar13 = 0;
        uVar8 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar10);
      }
      else {
        iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a703c)();
        if (iVar1 == 0) {
          iVar13 = 0;
          uVar8 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"memory allocation failure\n");
        }
        else {
          iVar13 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a6ffc)(iVar1,puVar11);
          if (iVar13 != 0) {
            uVar8 = 2;
            iVar13 = 0;
            if (iVar9 == 9) {
              uVar8 = 1;
            }
            goto LAB_0042ff50;
          }
          iVar13 = 0;
          uVar8 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"invalid compromised time %s\n",puVar11);
        }
      }
    }
  }
LAB_0042fe8c:
  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar3);
joined_r0x00430004:
  if (piVar6 == (int *)0x0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar13);
  }
  if (param_4 == (int *)0x0) {
    (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar1);
    return uVar8;
  }
  return uVar8;
}

