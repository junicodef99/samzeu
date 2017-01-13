package fr.utbm.samzeu.missile;
import fr.utbm.samzeu.missile.Missile;
import android.util.Log;

public class Main extends Thread
{
	public final static String TAG = "Missile";
	public static void main(String[] args) 
	{
		Missile ml = new Missile();
		try 
		{
			ml.mlbinInitUsb();
			ml.mlbinStop();

			ml.mlbinMoveLeft();
			Thread.sleep(2000);
			ml.mlbinStop();

			ml.mlbinMoveRight();
			Thread.sleep(2000);
			ml.mlbinStop();

			ml.mlbinFire();
			Thread.sleep(2000);
			ml.mlbinStop();
	
			ml.mlbinMoveUp();
			Thread.sleep(1000);
			ml.mlbinStop();

			ml.mlbinMoveDown();
			Thread.sleep(1000);
			ml.mlbinStop();

		}
		catch(Exception e)
		{
			Log.i(TAG, "Error "+e+"\n");
		}
	}
}
