using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TerrainPhysics : MonoBehaviour
{
	public PolyTerrain terrain;
	public float weight;
	public float friction = .5f;
	public float bounce = .3f;
	public float gravity = -9.81f;
	public float xVelocity = 0;
	public float yVelocity = 0;
	public float zVelocity = 0;
	public float terminalVelocity = -96;
	private bool onGround = false;

	public float tempFric = 100;

	void Start ()
	{
		
	}
	
	void Update ()
	{
		if (onGround)
		{
			xVelocity = Mathf.Lerp(xVelocity, 0, friction * Time.deltaTime * tempFric);
			zVelocity = Mathf.Lerp(zVelocity, 0, friction * Time.deltaTime * tempFric);
		}
		else
		{
			yVelocity += gravity * Time.deltaTime;
		}
		Mathf.Clamp(yVelocity, terminalVelocity, -terminalVelocity);
		transform.position += new Vector3(xVelocity, yVelocity, zVelocity);

		float groundHeight = terrain.getHeight(transform.position.x, transform.position.z);
		if (transform.position.y < groundHeight)
		{
			Vector3 n = terrain.getNormalForce(transform.position.x, transform.position.z);
			if (yVelocity > .1f)
			{
				n *= -yVelocity * bounce;
				xVelocity = n.x;
				yVelocity = n.y;
				zVelocity = n.z;
			}
			else
			{
				yVelocity = 0;
				if (!onGround)
				{
					xVelocity = n.x;
					zVelocity = n.z;
				}
			}

			transform.position = new Vector3(transform.position.x, groundHeight, transform.position.z);
			onGround = true;
		}
		else if (transform.position.y > groundHeight + .05f)
		{
			onGround = false;
		}
	}
}
