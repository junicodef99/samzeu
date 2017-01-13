package fr.utbm.samzeu.missile;

import android.util.Log;

public class Missile 
{
	static
	{
		Log.d("missile functions","Loading ...");
		System.loadLibrary("mlbin-jni");
	}

	public native int mlbinInitUsb();
	public native int mlbinFreeUsb();
	public native int mlbinFire();
	public native int mlbinMoveDown();
	public native int mlbinMoveLeft();
	public native int mlbinMoveRight();
	public native int mlbinMoveUp();
	public native int mlbinStop();
}
