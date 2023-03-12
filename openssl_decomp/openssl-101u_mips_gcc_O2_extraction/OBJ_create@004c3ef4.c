
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int OBJ_create(char *oid,char *sn,char *ln)

{
  int iVar1;
  void *ptr;
  int iVar2;
  ASN1_OBJECT *obj;
  
  iVar1 = (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(0,0,oid,0xffffffff);
  if (0 < iVar1) {
    ptr = CRYPTO_malloc(iVar1,"obj_dat.c",0x312);
    if (ptr == (void *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(8,100,0x41,"obj_dat.c",0x313);
      iVar1 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(ptr,iVar1,oid,0xffffffff);
      iVar1 = new_nid;
      if (iVar2 == 0) {
        obj = (ASN1_OBJECT *)0x0;
        iVar1 = 0;
      }
      else {
        new_nid = new_nid + 1;
        obj = (ASN1_OBJECT *)(*(code *)PTR_ASN1_OBJECT_create_006a84a8)(iVar1,ptr,iVar2,sn,ln);
        if (obj == (ASN1_OBJECT *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = OBJ_add_object(obj);
        }
      }
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)(obj);
      CRYPTO_free(ptr);
    }
    return iVar1;
  }
  return 0;
}

