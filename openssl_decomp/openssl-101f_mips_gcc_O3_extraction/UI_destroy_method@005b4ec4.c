
void UI_destroy_method(UI_METHOD *ui_method)

{
  (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)ui_method);
  *(undefined4 *)ui_method = 0;
                    /* WARNING: Could not recover jumptable at 0x005b4f04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(ui_method);
  return;
}

