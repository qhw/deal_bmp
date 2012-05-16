xcopy "%3\*.exe" "..\mSDK\bin\%2\" /Q /R /Y
xcopy "%3\*.exe" "..\%1\..\bin\%2\" /Q /R /Y 
xcopy "%3\*.dll" "..\bin\%2\" /Q /R /Y
xcopy "%3\*.dll" "..\mSDK\bin\%2\" /Q /R /Y
xcopy "%3\*.lib" "..\mSDK\lib\%2\" /Q /R /Y
xcopy "%3\*.pdb" "..\mSDK\lib\%2\" /Q /R /Y