
void * CMS_signed_get0_data_by_OBJ(CMS_SignerInfo *si,ASN1_OBJECT *oid,int lastpos,int type)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00610c58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_X509at_get0_data_by_OBJ_006a980c)(*(undefined4 *)(si + 0xc));
  return pvVar1;
}

