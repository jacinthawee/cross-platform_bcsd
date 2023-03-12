
int SMIME_crlf_copy(BIO *in,BIO *out,int flags)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char cVar9;
  BIO *out_00;
  BIO *pBVar10;
  BIO *pBVar11;
  uint in_a3;
  char *pcVar12;
  char acStack_42e [1026];
  BIO *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pBVar10 = out;
  pBVar11 = (BIO *)flags;
  uVar3 = (*(code *)PTR_BIO_f_buffer_006a8940)();
  iVar4 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    uVar3 = (*(code *)PTR_BIO_push_006a85c0)(iVar4,out);
    if ((flags & 0x80U) == 0) {
      if ((flags & 1U) != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(uVar3,"Content-Type: text/plain\r\n\r\n");
      }
      pcVar12 = acStack_42e + 2;
LAB_0060ecd4:
      iVar5 = (*(code *)PTR_BIO_gets_006a85d0)(in,pcVar12,0x400);
      if (0 < iVar5) {
        do {
          iVar6 = iVar5 + -1;
          pcVar7 = pcVar12 + iVar5 + -2;
          bVar1 = false;
          cVar9 = acStack_42e[iVar5 + 1];
          if (cVar9 == '\n') goto LAB_0060ed28;
          while (cVar9 == '\r') {
            iVar5 = iVar6;
            pcVar8 = pcVar7;
            if (iVar6 == 0) goto LAB_0060ed4c;
            while( true ) {
              pcVar7 = pcVar8 + -1;
              iVar6 = iVar5 + -1;
              cVar9 = *pcVar8;
              if (cVar9 != '\n') break;
LAB_0060ed28:
              bVar1 = true;
              iVar5 = iVar6;
              pcVar8 = pcVar7;
              if (iVar6 == 0) goto LAB_0060ed54;
            }
          }
          (*(code *)PTR_BIO_write_006a7f14)(uVar3,pcVar12,iVar5);
LAB_0060ed4c:
          if (!bVar1) goto LAB_0060ecd4;
LAB_0060ed54:
          (*(code *)PTR_BIO_write_006a7f14)(uVar3,"\r\n",2);
          iVar5 = (*(code *)PTR_BIO_gets_006a85d0)(in,pcVar12,0x400);
          if (iVar5 < 1) break;
        } while( true );
      }
    }
    else {
      while (iVar5 = (*(code *)PTR_BIO_read_006a85bc)(in,acStack_42e + 2,0x400), 0 < iVar5) {
        (*(code *)PTR_BIO_write_006a7f14)(uVar3,acStack_42e + 2,iVar5);
      }
    }
    in_a3 = 0;
    pBVar11 = (BIO *)0x0;
    pBVar10 = (BIO *)&DAT_0000000b;
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar3);
    (*(code *)PTR_BIO_pop_006a8ab4)(uVar3);
    (*(code *)PTR_BIO_free_006a7f70)(iVar4);
    iVar4 = 1;
  }
  if (local_2c == *(BIO **)puVar2) {
    return iVar4;
  }
  out_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((in_a3 & 0x1000) == 0) {
    (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(&_gp,out_00,pBVar10);
    iVar4 = 1;
  }
  else {
    pBVar10 = BIO_new_NDEF(out_00,(ASN1_VALUE *)pBVar10,(ASN1_ITEM *)&_gp);
    if (pBVar10 != (BIO *)0x0) {
      SMIME_crlf_copy(pBVar11,pBVar10,in_a3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar10,0xb,0,0);
      do {
        pBVar11 = (BIO *)(*(code *)PTR_BIO_pop_006a8ab4)(pBVar10);
        (*(code *)PTR_BIO_free_006a7f70)(pBVar10);
        pBVar10 = pBVar11;
      } while (out_00 != pBVar11);
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd3,0x41,"asn_mime.c",0x7d);
    iVar4 = 0;
  }
  return iVar4;
}

