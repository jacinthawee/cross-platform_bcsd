
ASN1_OBJECT * d2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uchar *puVar4;
  ASN1_OBJECT *pAVar5;
  uchar *puVar6;
  int iVar7;
  ASN1_OBJECT *unaff_s0;
  uchar *unaff_s2;
  uchar *puVar8;
  int unaff_s5;
  char *unaff_s6;
  uchar *local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_34 = *pp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar3 = ASN1_get_object(&local_34,&local_30,&local_2c,&iStack_28,length);
  puVar8 = local_34;
  if ((uVar3 & 0x80) == 0) {
    iVar7 = 0x74;
    if (local_2c == 6) {
      if (0 < local_30) {
        puVar4 = local_34;
        do {
          if ((*puVar4 == 0x80) && ((puVar4 == local_34 || (-1 < (char)puVar4[-1])))) {
            ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
            goto LAB_0054bc14;
          }
          puVar4 = puVar4 + 1;
        } while (puVar4 != local_34 + local_30);
      }
      unaff_s6 = "r";
      if (((a == (ASN1_OBJECT **)0x0) || (unaff_s0 = *a, unaff_s0 == (ASN1_OBJECT *)0x0)) ||
         ((unaff_s0->flags & 1U) == 0)) {
        unaff_s0 = (ASN1_OBJECT *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"a_object.c",0x15f);
        if (unaff_s0 == (ASN1_OBJECT *)0x0) {
          ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
          pAVar5 = (ASN1_OBJECT *)0x0;
          unaff_s2 = puVar8;
          goto LAB_0054bc18;
        }
        unaff_s0->length = 0;
        unaff_s0->data = (uchar *)0x0;
        unaff_s0->nid = 0;
        unaff_s0->sn = (char *)0x0;
        unaff_s0->ln = (char **)0x0;
        unaff_s0->length = 0;
        unaff_s0->flags = 1;
        puVar8 = local_34;
      }
      else {
        puVar4 = unaff_s0->data;
        unaff_s0->data = (uchar *)0x0;
        puVar1 = PTR_CRYPTO_free_006a7f88;
        unaff_s2 = local_34;
        if (puVar4 == (uchar *)0x0) goto LAB_0054bd74;
        if (local_30 <= unaff_s0->length) {
          puVar4 = (uchar *)(*(code *)PTR_memcpy_006aabf4)(puVar4,local_34,local_30);
          puVar6 = puVar8 + local_30;
          unaff_s0->data = puVar4;
          unaff_s0->length = local_30;
          unaff_s0->sn = (char *)0x0;
          unaff_s0->ln = (char **)0x0;
          *a = unaff_s0;
          pAVar5 = unaff_s0;
          goto LAB_0054bbd8;
        }
        unaff_s0->length = 0;
        (*(code *)puVar1)(puVar4);
      }
      while( true ) {
        iVar7 = 1;
        if (local_30 != 0) {
          iVar7 = local_30;
        }
        iVar7 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar7,unaff_s6 + -0x611c,0x143);
        puVar1 = PTR_memcpy_006aabf4;
        if (iVar7 == 0) {
          ERR_put_error(0xd,0xc4,0x41,unaff_s6 + -0x611c,0x155);
          if ((a == (ASN1_OBJECT **)0x0) ||
             (pAVar5 = (ASN1_OBJECT *)0x0, unaff_s2 = puVar8, *a != unaff_s0)) {
            ASN1_OBJECT_free(unaff_s0);
LAB_0054bc14:
            pAVar5 = (ASN1_OBJECT *)0x0;
            unaff_s2 = puVar8;
          }
        }
        else {
          unaff_s0->flags = unaff_s0->flags | 8;
          puVar4 = (uchar *)(*(code *)puVar1)(iVar7,puVar8,local_30);
          puVar6 = puVar8 + local_30;
          unaff_s0->data = puVar4;
          unaff_s0->length = local_30;
          unaff_s0->sn = (char *)0x0;
          unaff_s0->ln = (char **)0x0;
          pAVar5 = unaff_s0;
          if (a != (ASN1_OBJECT **)0x0) {
            *a = unaff_s0;
          }
LAB_0054bbd8:
          *pp = puVar6;
          unaff_s0 = pAVar5;
          unaff_s2 = puVar8;
        }
LAB_0054bc18:
        if (local_24 == *(int *)puVar2) break;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0054bd74:
        unaff_s0->length = 0;
        puVar8 = unaff_s2;
      }
      return pAVar5;
    }
  }
  else {
    iVar7 = 0x66;
  }
  ERR_put_error(0xd,0x93,iVar7,"a_object.c",0x11b);
  pAVar5 = (ASN1_OBJECT *)0x0;
  local_30 = unaff_s5;
  goto LAB_0054bc18;
}

